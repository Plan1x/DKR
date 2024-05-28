#pragma once
#include <iostream>
#include "Vector.h"
using namespace std;
class Console
{
public:
	
	
	bool flag_for_clear;
	Vector* p_arr;
	
	void application();
	
	friend ostream& operator<< (ostream& out, const Console& object);

	Console();
	~Console();
	
	
private:

	int elem_size_m;
	int step_m;
	int size_m;
	int counter_m;
	int prev_counter;

	bool flag;

	

	Vector a;
	Vector temp;

	void expandArray(int size);
	void setValue(Vector a);
	int getSize();
	int getElemSize();

};
