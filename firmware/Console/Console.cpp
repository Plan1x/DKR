#include "Console.h"
Console::Console()
{
	counter_m = 0;
	
}
void Console::application()
{

	cout << "Choose preferable method : 1 - vector abs, 2 - scalar multiply, 3 - sum of two vectors, 4 - difference of two vectors, 5 - multiply vector on constant, 6 - Check coliniar or ortogonal" << endl;
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
		cin >> b.a1_m;
		cout << "Enter b2: ";
		cin >> b.a2_m;
		

		cout << endl;
		cout << "scalar = " << a.scalar(a,b) << endl;
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
		cin >> b.a1_m;
		cout << "Enter b2: ";
		cin >> b.a2_m;

		temp = temp.vector_plus(a, b);
		temp.counter = 3;
		cout << temp;
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
		cin >> b.a1_m;
		cout << "Enter b2: ";
		cin >> b.a2_m;
		
		temp = temp.vector_minus(a, b);
		temp.counter = 4;
		cout << temp;
		break;
	case 5:// multiply on constant
		int val;
		cout << "Enter a1: ";
		cin >> a.a1_m;
		cout << "Enter a1: ";
		cin >> a.a2_m;
		
		
		cout << "Enter a multiplier value: ";
		cin >> val;
		
		temp = temp.multiply_vector_on_const(a, val);
		temp.counter = 5;
		cout << temp;
		
		break;
	case 6:// Coliniar or ortogonal
		bool coliniar, ortogonal;
		cout << "Enter vector a parameters" << endl;
		cout << "Enter a1: ";
		cin >> a.a1_m;
		cout << "Enter a2: ";
		cin >> a.a1_m;


		cout << endl;

		cout << "Enter vector b parameters" << endl;
		cout << "Enter b1: ";
		cin >> b.a1_m;
		cout << "Enter b2: ";
		cin >> b.a2_m;
		
		coliniar = temp.coliniar(a,b);
		ortogonal = temp.ortogonal(a, b);

		if (coliniar && !ortogonal)
		{
			cout << "Vectors a and b are coliniar" << endl;
		}
		else if (!coliniar && ortogonal)
		{
			cout << "Vectors a and b are ortogonal" << endl;
		}
		else if (coliniar && ortogonal)
		{
			cout << "Vectors a and b are ortogonal and coliniar" << endl;
		}
		else
		{
			cout << "Vectors a and b are not ortogonal and not coliniar" << endl;
		}


		break;
	default:// incorrect var
		while (counter_m < 1 || counter_m > 6)
		{
			cout << endl;
			cout << "Incorrect variant, choose again" << endl;
			return application();
			
		}
		break;
	}
	cout << endl;
}
/*ostream& operator<< (ostream& out, const Vector& obj)
{
		
	
		return out;
}*/