#pragma once
#include <math.h>
#include <iostream>
using namespace std;
class Vector
{
public:

	/////////Operational variables
	float a1_m, a2_m;
	int counter;
	float input_a1, input_a2;
	float out_a1, out_a2;
	float result;
	int constant;
	bool isColiniar, isOrtogonal;
	/////////Operational variables
	~Vector();
	Vector();
	Vector(int y1, int x1, int y2, int x2);
	float abs(Vector a);
	float scalar(Vector a);
	Vector vector_plus(Vector a);
	Vector vector_minus(Vector a);
	Vector multiply_vector_on_const(Vector a, int val);
	bool coliniar(Vector a);
	bool ortogonal(Vector a);
	friend ostream& operator<< (ostream& out, const Vector& arr);

private:

};