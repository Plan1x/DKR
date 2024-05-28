#pragma once
#include <iostream>
#include "Vector.h"
#include "Logger.h"
#include "AES_Coding.h"
#include <sstream>
using namespace std;
class Console
{
public:


	bool flag_for_clear;
	Vector* p_arr;

	void application();

	friend ostream& operator<< (ostream& out, const Console& object);

	Console(const Aes& obj);
	~Console();


private:

	int elem_size_m;
	int step_m;
	int size_m;
	int counter_m;
	int prev_counter, temp_counter;

	bool flag;



	string out, encrypt_out;

	Vector a;
	Vector temp;

	ostringstream oss;
	Logger log;

	Aes enc;

	void expandArray(int size);
	void setValue(Vector a);
	int getSize();
	int getElemSize();
	void to_log(int counter);
	void to_encrypt(int counter);

};
