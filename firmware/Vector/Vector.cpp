#include "Vector.h"
Vector :: ~Vector()
{
	delete[] p_arr;
}
Vector::Vector()
{

}
Vector::Vector(int y1, int x1, int y2, int x2)
{
	/*this->y1_m = y1;
	this->x1_m = x1;
	this->y2_m = y2;
	this->x2_m = x2;*/
	this->p_arr = nullptr;
	size_m = 0;
	elem_size_m = 0;
	step_m = 0;
	counter = 0;

}
float Vector::abs(Vector a)
{	
	return sqrt(pow(a.a1_m, 2) + pow((a.a2_m), 2));
}
float Vector::scalar(Vector a, Vector b)
{
	return (a.a1_m * b.a1_m) + (a.a2_m * b.a2_m);
}
Vector  Vector ::vector_plus(Vector a, Vector b)
{
	Vector res(0,0,0,0);
	// Calculating Vectors arguments
	/*a.a1_m = (a.x2_m - a.x1_m);
	a.a2_m = (a.y2_m - a.y1_m);
	b.a1_m = (b.x2_m - b.x1_m);
	b.a2_m = (b.y2_m - b.y1_m);*/
	// Calculating Vectors sum
	res.a1_m = a.a1_m + b.a1_m;
	res.a2_m = a.a2_m + b.a2_m;

	return res;
}
Vector Vector::vector_minus(Vector a, Vector b)
{
	Vector res(0, 0, 0, 0);
	// Calculating Vectors arguments
	/*a.a1_m = (a.x2_m - a.x1_m);
	a.a2_m = (a.y2_m - a.y1_m);
	b.a1_m = (b.x2_m - b.x1_m);
	b.a2_m = (b.y2_m - b.y1_m);*/
	// Calculating Vectors difference
	res.a1_m = a.a1_m - b.a1_m;
	res.a2_m = a.a2_m - b.a2_m;

	return res;
}
Vector Vector::multiply_vector_on_const(Vector a,  int val)
{
	a.a1_m = a.a1_m * val;
	a.a2_m = a.a2_m * val;
	return a;
}
bool Vector::coliniar(Vector a, Vector b)
{
	/*a.a1_m = (a.x2_m - a.x1_m);
	a.a2_m = (a.y2_m - a.y1_m);
	b.a1_m = (b.x2_m - b.x1_m);
	b.a2_m = (b.y2_m - b.y1_m);*/
	if (b.a1_m == 0 || b.a2_m == 0)//Todo 
	{
		float val = b.a2_m / a.a2_m;
		
			return ((a.a1_m * val == b.a1_m) && (a.a2_m * val == b.a2_m)) ? true : false;
	}
	else
	{
	return ((a.a1_m / b.a1_m) == (a.a2_m / b.a2_m)) ? true : false;
	}
	
}
bool Vector::ortogonal(Vector a, Vector b)
{
	return (scalar(a, b) == 0) ? true : false;
}
void Vector::expandArray(int size)
{
	Vector* new_arr = new Vector[size];
	step_m = size - size_m;
	copy(p_arr, (p_arr + size_m), new_arr);
	delete[] p_arr;
	p_arr = new_arr;
	size_m = size;

}
int Vector::getSize()
{
	return size_m;
}
int Vector::getElemSize()
{

	return elem_size_m;
}
void Vector::setValue(Vector a)
{
	if (p_arr == nullptr && getSize() == 0)
	{
		int argument = getSize() + 1;
		expandArray(argument);
		elem_size_m += step_m;
		p_arr[elem_size_m - 1] = a;

	}
	else
	{
		int temp = getElemSize();
		if (temp + 1 > getSize())
		{
			int argument = temp + 1;
			expandArray(argument);
			elem_size_m += step_m;

			p_arr[elem_size_m - 1] = a;

		}

	}
}
ostream& operator << (ostream& out, const Vector& arr)
{

	out << endl;
	out << "Vector x = " << arr.a1_m << endl;
	out << "Vector y = " << arr.a2_m << endl;
	cout << endl;

	return out;

}
/*int Vector::counter_geter(int counter)
{
	return counter; 
}*/