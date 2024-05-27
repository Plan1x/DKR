#pragma once
#include "iostream"
#include "Console.h"
#include <fstream>
#include <string>
#include "AES_Coding.h"
using namespace std;

class Logger
{
public:
	Aes a;
	//Console b;
	ofstream file;
	string key_s;
	Logger();
	void open(const string& filename);
	void close();
	void write(const Console& console);

private:
};