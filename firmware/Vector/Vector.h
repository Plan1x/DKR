#pragma once
#include <math.h>
#include <iostream>
using namespace std;
class Vector
{
public:
	
	Vector* p_arr;
	
	
	
	//float y1_m, x1_m, y2_m, x2_m;
	float a1_m, a2_m;
	int counter;

	~Vector();
	Vector();
	Vector(int y1, int x1, int y2, int x2);
	float abs(Vector a);
	float scalar(Vector a, Vector b);
	Vector vector_plus(Vector a, Vector b);
	Vector vector_minus(Vector a, Vector b);
	Vector multiply_vector_on_const(Vector a, int val);
	bool coliniar(Vector a, Vector b);
	bool ortogonal(Vector a, Vector b);
    friend ostream& operator<< (ostream& out, const Vector& arr);
	//int counter_geter(int counter);//counter for statemachine
	int getSize();
	int getElemSize();
	void expandArray(int size);
	void setValue(Vector a);
private:
	int elem_size_m;
	int step_m;
	int size_m;
};