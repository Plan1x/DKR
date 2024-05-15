#pragma once
#include <iostream>
#include "Vector.h"
using namespace std;
class Console
{
public:
	Vector* p_arr;
	int elem_size_m;
	int step_m;
	int size_m;
	bool flag;
	Vector a;
	Vector temp;
	int counter_m;
	int prev_counter;
	void application();
	void expandArray(int size);
	void setValue(Vector a);
	int getSize();
	int getElemSize();
	friend ostream& operator<< (ostream& out, const Console& object);
	Console();
	
	
private:
};
