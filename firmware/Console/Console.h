#pragma once
#include <iostream>
#include "Vector.h"
using namespace std;
class Console
{
public:
	Vector a, b;
	Vector temp;
	int counter_m;
	void application();
	Console();
	 //friend ostream& operator<< (ostream& out, const Vector& obj);
private:
};