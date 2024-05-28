// Dkr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Console.h"
#include "Vector.h"
#include "Logger.h"
#include "AES_Coding.h"
#include <sstream>


using namespace std;

int main()
{
	Aes b;
	b.AES_init();
	Console a(b);

	a.application();


	delete[] a.p_arr;

	return main();
}


