#include "Console.h"
Console::Console()
{
	counter_m = 0;
	p_arr = nullptr;
	size_m = 0;
	elem_size_m = 0;
	step_m = 0;
	prev_counter = 0;
	flag = 0;
	flag_for_clear = 0;
}
Console :: ~Console()
{
	delete[] p_arr;
}
void Console::application()
{

	cout << "Choose preferable method : 1 - vector abs, 2 - scalar multiply, 3 - sum of two vectors, 4 - difference of two vectors, 5 - multiply vector on constant, 6 - Check coliniar or ortogonal, 7 - Save all information to logger file" << endl;
	cout << ">";
	cin >> counter_m;
	
	switch (counter_m)
	{
	case 1:// abs
		cout << "Enter a1: ";
		cin >> a.a1_m;
		cout << "Enter a2: ";
		cin >> a.a2_m;
		
		cout << "Abs = " << a.abs(a) << endl;
		prev_counter = 1;
		a.counter = prev_counter;
		setValue(a);
		
		break;
	case 2:// scalar

		cout << "Enter vector a parameters" << endl;
		cout << "Enter a1: ";
		cin >> a.a1_m;
		cout << "Enter a2: ";
		cin >> a.a2_m;
		

		cout << endl;

		cout << "Enter vector b parameters" << endl;
		cout << "Enter b1: ";
		cin >> a.out_a1;
		cout << "Enter b2: ";
		cin >> a.out_a2;
		
		
		cout << endl;
		cout << "scalar = " << a.scalar(a) << endl;
		prev_counter = 2;
		a.counter = prev_counter;
		setValue(a);
		break;
	case 3:// sum
		
		cout << "Enter vector a parameters" << endl;
		cout << "Enter a1: ";
		cin >> a.a1_m;
		cout << "Enter a2: ";
		cin >> a.a2_m;
		

		cout << endl;

		cout << "Enter vector b parameters" << endl;
		cout << "Enter b1: ";
		cin >> a.out_a1;
		cout << "Enter b2: ";
		cin >> a.out_a2;

		
		
		a = a.vector_plus(a);
		prev_counter = 3;
		a.counter = prev_counter;
		setValue(a);
		
		cout << a;
		
		break;
	case 4:// difference
		cout << "Enter vector a parameters" << endl;
		cout << "Enter a1: ";
		cin >> a.a1_m;
		cout << "Enter a2: ";
		cin >> a.a2_m;

		
		cout << endl;

		cout << "Enter vector b parameters" << endl;
		cout << "Enter b1: ";
		cin >> a.out_a1;
		cout << "Enter b2: ";
		cin >> a.out_a2;
		
		a = a.vector_minus(a);
		prev_counter = 4;
		a.counter = prev_counter;
		setValue(a);
		cout << a;
		break;
	case 5:// multiply on constant
		int val;
		cout << "Enter a1: ";
		cin >> a.a1_m;
		cout << "Enter a1: ";
		cin >> a.a2_m;
		
		
		cout << "Enter a multiplier value: ";
		cin >> val;
		
		a = a.multiply_vector_on_const(a, val);
		prev_counter = 5;
		a.counter = prev_counter;
		cout << a;
		setValue(a);
		
		break;
	case 6:// Coliniar or ortogonal
		bool coliniar, ortogonal;
		cout << "Enter vector a parameters" << endl;
		cout << "Enter a1: ";
		cin >> a.input_a1;
		cout << "Enter a2: ";
		cin >> a.input_a2;

		

		cout << endl;

		cout << "Enter vector b parameters" << endl;
		cout << "Enter b1: ";
		cin >> a.out_a1;
		cout << "Enter b2: ";
		cin >> a.out_a2;
		
		
		 
		coliniar = a.coliniar(a);
		ortogonal = a.ortogonal(a);
		prev_counter = 6;
		a.counter = prev_counter;
		setValue(a);
		
		
		if (coliniar && !ortogonal)
		{
			cout << "Vectors 1 and 2 are coliniar" << endl;
		}
		else if (!coliniar && ortogonal)
		{
			cout << "Vectors 1 and 2 are ortogonal" << endl;
		}
		else if (coliniar && ortogonal)
		{
			cout << "Vectors 1 and 2 are ortogonal and coliniar" << endl;
		}
		else
		{
			cout << "Vectors 1 and 2 are not ortogonal and not coliniar" << endl;
		}

		break;

	case 7:

		flag_for_clear = 1;// flag to delete arr and close logger file
		
		break;
	default:// incorrect var
		while (counter_m < 1 || counter_m > 7)
		{
			cout << endl;
			cout << "Incorrect variant, choose again" << endl;
			//return application();
			break;
			
		}
		break;
	}
	
	cout << endl;
}
/*ostream& operator<< (ostream& out, const Vector& obj)
{
		
	
		return out;
}*/
void Console::expandArray(int size)
{
	Vector* new_arr = new Vector[size];
	step_m = size - size_m;
	copy(p_arr, (p_arr + size_m), new_arr);
	delete[] p_arr;
	p_arr = new_arr;
	size_m = size;

}
void Console::setValue(Vector a)
{
	if (p_arr == nullptr && size_m == 0)
	{
		int argument = size_m + 1;
		expandArray(argument);
		elem_size_m += step_m;
		p_arr[elem_size_m - 1] = a;

	}
	else
	{
		int temp = getElemSize();
		if (temp + 1 > size_m)
		{
			int argument = temp + 1;
			expandArray(argument);
			elem_size_m += step_m;

			p_arr[elem_size_m - 1] = a;

		}

	}
}
int Console::getSize()
{
	return size_m;
}
int Console::getElemSize()
{

	return elem_size_m;
}
 ostream& operator<< (ostream& out, const Console& object)
{
	out << "***************************************";
	out << endl;
	for (int i = 0; i < object.size_m; i++)
	{
		
		
		switch (object.p_arr[i].counter)
		{
		case 1:
			out << endl;
			//out << "operation # " << (i + 1) << endl;
			out << "Operation type: module" << endl;
			out << "Input data:" << endl;
			out << "x = " << object.p_arr[i].a1_m << endl; 
			out << "y = " << object.p_arr[i].a2_m << endl;
			out << "Output data:" << endl;
			out << "Module = " << object.p_arr[i].result << endl;
			out << endl;
			
			break;
		case 2:
			out << endl;
			//out << "operation # " << (i + 1) << endl;
			out << "Operation type: scalar multiply" << endl;
			out << "Input data:" << endl;
			out << "Vector 1:" << endl;
			out << "x = " << object.p_arr[i].a1_m << endl;
			out << "y = " << object.p_arr[i].a2_m << endl;
			out << "Vector 2:" << endl;
			out << "x = " << object.p_arr[i].out_a1 << endl;
			out << "y = " << object.p_arr[i].out_a2 << endl;
			out << "Output data:" << endl;
			out << "Scalar = " << object.p_arr[i].result << endl;
			out << endl;
			break;
		case 3:
			out << endl;
			//out << "operation # " << (i + 1) << endl;
			out << "Operation type: sum" << endl;
			out << "Input data:" << endl;
			out << "Vector 1:" << endl;
			out << "x = " << object.p_arr[i].input_a1 << endl;
			out << "y = " << object.p_arr[i].input_a2 << endl;
			out << "Vector 2:" << endl;
			out << "x = " << object.p_arr[i].out_a1 << endl;
			out << "y = " << object.p_arr[i].out_a2 << endl;
			out << "Output data:" << endl;
			out << "Result Vector: " <<  endl;
			out << "x = " <<  object.p_arr[i].a1_m << endl;
			out << "y = " <<  object.p_arr[i].a2_m << endl;
			out << endl;
			break;
		case 4:
			out << endl;
			//out << "operation # " << (i + 1) << endl;
			out << "Operation type: difference" << endl;
			out << "Input data:" << endl;
			out << "Vector 1:" << endl;
			out << "x = " << object.p_arr[i].input_a1 << endl;
			out << "y = " << object.p_arr[i].input_a2 << endl;
			out << "Vector 2:" << endl;
			out << "x = " << object.p_arr[i].out_a1 << endl;
			out << "y = " << object.p_arr[i].out_a2 << endl;
			out << "Output data:" << endl;
			out << "Result Vector: " << endl;
			out << "x = " << object.p_arr[i].a1_m << endl;
			out << "y = " << object.p_arr[i].a2_m << endl;
			out << endl;
			break;
		case 5:
			out << endl;
			//out << "operation # " << (i + 1) << endl;
			out << "Operation type: multiply on constant" << endl;
			out << "Input data:" << endl;
			out << "Vector:" << endl;
			out << "x = " << object.p_arr[i].input_a1 << endl;
			out << "y = " << object.p_arr[i].input_a2 << endl;
			out << "Multiplication constant = " << object.p_arr[i].constant << endl;
			out << "Output data:" << endl;
			out << "Result Vector: " << endl;
			out << "x = " << object.p_arr[i].a1_m << endl;
			out << "y = " << object.p_arr[i].a2_m << endl;
			out << endl;
			
			break;
		case 6:
			out << endl;
			//out << "operation # " << (i + 1) << endl;
			out << "Operation type: Coliniar or ortogonal" << endl;
			out << "Input data:" << endl;
			out << "Vector 1:" << endl;
			out << "x = " << object.p_arr[i].input_a1 << endl;
			out << "y = " << object.p_arr[i].input_a2 << endl;
			out << "Vector 2:" << endl;
			out << "x = " << object.p_arr[i].out_a1 << endl;
			out << "y = " << object.p_arr[i].out_a2 << endl;
			out << "Output data:" << endl;
			out << "Result: " << endl;
			if (object.p_arr[i].isColiniar && !object.p_arr[i].isOrtogonal)
			{
				out << "Vectors 1 and 2 are coliniar" << endl;
			}
			else if (!object.p_arr[i].isColiniar && object.p_arr[i].isOrtogonal)
			{
				out << "Vectors 1 and 2 are ortogonal" << endl;
			}
			else if (object.p_arr[i].isColiniar && object.p_arr[i].isOrtogonal)
			{
				out << "Vectors 1 and 2 are ortogonal and coliniar" << endl;
			}
			else
			{
				out << "Vectors 1 and 2 are not ortogonal and not coliniar" << endl;
			}
			out << endl;
		
			break;
		}
	}
	out << "***************************************" << endl;
	return out;
	
}