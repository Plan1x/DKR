#include "Vector.h"
Vector :: ~Vector()
{
	//delete[] p_arr;
}
Vector::Vector()
{

}
Vector::Vector(int y1, int x1, int y2, int x2)
{

	counter = 0;

}
float Vector::abs(Vector a)
{
	result = sqrt(pow(a.a1_m, 2) + pow((a.a2_m), 2));
	return sqrt(pow(a.a1_m, 2) + pow((a.a2_m), 2));
}
float Vector::scalar(Vector a)
{
	result = (a.a1_m * a.out_a1) + (a.a2_m * a.out_a2);
	return (a.a1_m * a.out_a1) + (a.a2_m * a.out_a2);
}
Vector  Vector::vector_plus(Vector a)
{
	Vector res(0, 0, 0, 0);
	res.input_a1 = a.a1_m;
	res.input_a2 = a.a2_m;
	res.out_a1 = a.out_a1;
	res.out_a2 = a.out_a2;

	res.a1_m = a.a1_m + a.out_a1;
	res.a2_m = a.a2_m + a.out_a2;

	return res;
}
Vector Vector::vector_minus(Vector a)
{
	Vector res(0, 0, 0, 0);
	res.input_a1 = a.a1_m;
	res.input_a2 = a.a2_m;
	res.out_a1 = a.out_a1;
	res.out_a2 = a.out_a2;

	res.a1_m = a.a1_m - a.out_a1;
	res.a2_m = a.a2_m - a.out_a2;

	return res;
}
Vector Vector::multiply_vector_on_const(Vector a, int val)
{
	a.input_a1 = a.a1_m;
	a.input_a2 = a.a2_m;
	a.a1_m = a.a1_m * val;
	a.a2_m = a.a2_m * val;
	a.constant = val;
	return a;
}
bool Vector::coliniar(Vector a)
{

	if (a.out_a1 == 0 || a.out_a2 == 0)
	{
		if (a.out_a1 == 0)
		{
			float val = a.out_a2 / a.input_a2;
			isColiniar = ((a.input_a1 * val == a.out_a1) && (a.input_a2 * val == a.out_a2)) ? true : false;
			return isColiniar;
		}
		else if (a.out_a2 == 0)
		{
			float val = a.out_a1 / a.input_a1;
			isColiniar = ((a.input_a1 * val == a.out_a1) && (a.input_a2 * val == a.out_a2)) ? true : false;
			return isColiniar;
		}



	}
	else
	{
		isColiniar = ((a.input_a1 / a.out_a1) == (a.input_a2 / a.out_a2)) ? true : false;
		return isColiniar;
	}



}
bool Vector::ortogonal(Vector a)
{
	;
	isOrtogonal = (scalar(a) == 0) ? true : false;
	return isOrtogonal;
}


ostream& operator << (ostream& out, const Vector& arr)
{



	out << endl;
	out << "Vector x = " << arr.a1_m << endl;
	out << "Vector y = " << arr.a2_m << endl;
	out << endl;





	return out;

}
