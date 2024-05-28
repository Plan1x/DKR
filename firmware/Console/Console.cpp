#include "Console.h"
Console::Console(const Aes& obj)
{
	counter_m = 0;
	p_arr = nullptr;
	size_m = 0;
	elem_size_m = 0;
	step_m = 0;
	prev_counter = 0;
	flag = 0;
	flag_for_clear = 0;
	for (int i = 0; i < 16; i++)
	{
		enc.key[i] = obj.key[i];
		enc.iv[i] = obj.iv[i];
	}
	//enc.AES_init();//generating keys
	//Console b();
}
Console :: ~Console()
{
	delete[] p_arr;
}
void Console::application()
{

	cout << "Choose preferable method : 1 - vector abs, 2 - scalar multiply, 3 - sum of two vectors, 4 - difference of two vectors, 5 - multiply vector on constant, 6 - Check coliniar or ortogonal, 7 - Exit" << endl;
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
		//to_log(prev_counter);


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
		//to_log(prev_counter);

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
		//to_log(prev_counter);


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
		//to_log(prev_counter);
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
		//to_log(prev_counter);
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
		flag_for_clear = 1;//clearing all
		break;
	default:// incorrect var
		while (counter_m < 1 || counter_m > 7)
		{
			cout << endl;
			cout << "Incorrect variant, choose again" << endl;

			break;

		}
		break;
	}
	temp_counter = prev_counter;
	to_log(prev_counter);
	to_encrypt(prev_counter);



	cout << endl;
}

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

void Console::to_log(int counter)
{
	log.open("log.txt");
	oss << "***************************************" << endl;
	switch (counter)
	{
	case 1:

		oss << "Operation type: module" << endl;
		oss << "Input data:" << endl;
		oss << "x = " << a.a1_m << endl;
		oss << "y = " << a.a2_m << endl;
		oss << "Output data:" << endl;
		oss << "Module = " << a.result << endl;
		oss << "***************************************" << endl;

		out = oss.str();
		//log.write(out);
		break;
	case 2:
		oss << "Operation type: scalar multiply" << endl;
		oss << "Input data:" << endl;
		oss << "Vector 1:" << endl;
		oss << "x = " << a.a1_m << endl;
		oss << "y = " << a.a2_m << endl;
		oss << "Vector 2:" << endl;
		oss << "x = " << a.out_a1 << endl;
		oss << "y = " << a.out_a2 << endl;
		oss << "Output data:" << endl;
		oss << "Scalar = " << a.result << endl;
		oss << "***************************************" << endl;
		out = oss.str();
		//log.write(out);
		break;
	case 3:
		oss << "Operation type: sum" << endl;
		oss << "Input data:" << endl;
		oss << "Vector 1:" << endl;
		oss << "x = " << a.input_a1 << endl;
		oss << "y = " << a.input_a2 << endl;
		oss << "Vector 2:" << endl;
		oss << "x = " << a.out_a1 << endl;
		oss << "y = " << a.out_a2 << endl;
		oss << "Output data:" << endl;
		oss << "Result Vector: " << endl;
		oss << "x = " << a.a1_m << endl;
		oss << "y = " << a.a2_m << endl;
		oss << "***************************************" << endl;
		out = oss.str();
		//log.write(out);
		break;
	case 4:
		oss << "Operation type: difference" << endl;
		oss << "Input data:" << endl;
		oss << "Vector 1:" << endl;
		oss << "x = " << a.input_a1 << endl;
		oss << "y = " << a.input_a2 << endl;
		oss << "Vector 2:" << endl;
		oss << "x = " << a.out_a1 << endl;
		oss << "y = " << a.out_a2 << endl;
		oss << "Output data:" << endl;
		oss << "Result Vector: " << endl;
		oss << "x = " << a.a1_m << endl;
		oss << "y = " << a.a2_m << endl;
		oss << "***************************************" << endl;
		out = oss.str();
		//log.write(out);
		break;
	case 5:
		oss << "Operation type: multiply on constant" << endl;
		oss << "Input data:" << endl;
		oss << "Vector:" << endl;
		oss << "x = " << a.input_a1 << endl;
		oss << "y = " << a.input_a2 << endl;
		oss << "Multiplication constant = " << a.constant << endl;
		oss << "Output data:" << endl;
		oss << "Result Vector: " << endl;
		oss << "x = " << a.a1_m << endl;
		oss << "y = " << a.a2_m << endl;
		oss << "***************************************" << endl;
		out = oss.str();

		break;
	case 6:
		oss << "Operation type: Coliniar or ortogonal" << endl;
		oss << "Input data:" << endl;
		oss << "Vector 1:" << endl;
		oss << "x = " << a.input_a1 << endl;
		oss << "y = " << a.input_a2 << endl;
		oss << "Vector 2:" << endl;
		oss << "x = " << a.out_a1 << endl;
		oss << "y = " << a.out_a2 << endl;
		oss << "Output data:" << endl;
		oss << "Result: " << endl;
		if (a.isColiniar && !a.isOrtogonal)
		{
			oss << "Vectors 1 and 2 are coliniar" << endl;
		}
		else if (!a.isColiniar && a.isOrtogonal)
		{
			oss << "Vectors 1 and 2 are ortogonal" << endl;
		}
		else if (a.isColiniar && a.isOrtogonal)
		{
			oss << "Vectors 1 and 2 are ortogonal and coliniar" << endl;
		}
		else
		{
			oss << "Vectors 1 and 2 are not ortogonal and not coliniar" << endl;
		}
		oss << "***************************************" << endl;
		out = oss.str();

		break;
	}

	log.write(out);
	log.close();



}
void Console::to_encrypt(int counter)
{
	log.open("encrypt.txt");
	oss << endl;
	switch (counter)
	{
	case 1:

		oss << "1" << endl;
		oss << a.a1_m << endl;
		oss << a.a2_m << endl;
		oss << a.result << endl;

		encrypt_out = oss.str();
		break;

	case 2:
		oss << "2" << endl;
		oss << a.a1_m << endl;
		oss << a.a2_m << endl;
		oss << a.out_a1 << endl;
		oss << a.out_a2 << endl;
		oss << a.result << endl;

		encrypt_out = oss.str();
		break;

	case 3:
		oss << "3" << endl;
		oss << a.input_a1 << endl;
		oss << a.input_a2 << endl;

		oss << a.out_a1 << endl;
		oss << a.out_a2 << endl;

		oss << a.a1_m << endl;
		oss << a.a2_m << endl;

		encrypt_out = oss.str();
		break;
	case 4:
		oss << "4" << endl;
		oss << a.input_a1 << endl;
		oss << a.input_a2 << endl;

		oss << a.out_a1 << endl;
		oss << a.out_a2 << endl;

		oss << a.a1_m << endl;
		oss << a.a2_m << endl;

		encrypt_out = oss.str();
		break;
	case 5:

		oss << "5" << endl;
		oss << a.input_a1 << endl;
		oss << a.input_a2 << endl;
		oss << a.constant << endl;
		oss << a.a1_m << endl;
		oss << a.a2_m << endl;

		encrypt_out = oss.str();
		break;
	case 6:

		oss << "6" << endl;
		oss << a.input_a1 << endl;
		oss << a.input_a2 << endl;

		oss << a.out_a1 << endl;
		oss << a.out_a2 << endl;

		encrypt_out = oss.str();
		break;
	}
	oss << endl;
	//enc.AES_init();
	enc.aes_encrypt(encrypt_out, enc.cipher_text, enc.key, enc.iv);
	log.write_encrypt_data(enc);
	log.close();
	/*log.read_data("encrypt.txt"); // not working
	enc.aes_decrypt(log.test, enc.decoded_text, enc.key, enc.iv);
	cout << enc.decoded_text;*/
}
/*ostream& operator<< (ostream& out, const Console& object)// for encrypting data
{

	for (int i = 0; i < object.size_m; i++)
	{


		switch (object.p_arr[i].counter)
		{
		case 1:

			out << "1" << endl;
			out << object.p_arr[i].a1_m << endl;
			out << object.p_arr[i].a2_m << endl;
			out << object.p_arr[i].result << endl;


			break;
		case 2:
			out << "2" << endl;
			out << object.p_arr[i].a1_m << endl;
			out << object.p_arr[i].a2_m << endl;
			out << object.p_arr[i].out_a1 << endl;
			out << object.p_arr[i].out_a2 << endl;
			out << object.p_arr[i].result << endl;

			break;
		case 3:
			out << "3" << endl;
			out << object.p_arr[i].input_a1 << endl;
			out << object.p_arr[i].input_a2 << endl;

			out << object.p_arr[i].out_a1 << endl;
			out << object.p_arr[i].out_a2 << endl;

			out << object.p_arr[i].a1_m << endl;
			out << object.p_arr[i].a2_m << endl;

			break;
		case 4:
			out << "4" << endl;
			out << object.p_arr[i].input_a1 << endl;
			out << object.p_arr[i].input_a2 << endl;

			out << object.p_arr[i].out_a1 << endl;
			out << object.p_arr[i].out_a2 << endl;

			out << object.p_arr[i].a1_m << endl;
			out << object.p_arr[i].a2_m << endl;

			break;
		case 5:

			out << "5" << endl;
			out << object.p_arr[i].input_a1 << endl;
			out << object.p_arr[i].input_a2 << endl;
			out << object.p_arr[i].constant << endl;
			out << object.p_arr[i].a1_m << endl;
			out << object.p_arr[i].a2_m << endl;


			break;
		case 6:

			out << "6" << endl;
			out << object.p_arr[i].input_a1 << endl;
			out << object.p_arr[i].input_a2 << endl;

			out << object.p_arr[i].out_a1 << endl;
			out << object.p_arr[i].out_a2 << endl;


			break;
		}
	}

	return out;

}*/