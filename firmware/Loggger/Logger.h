#pragma once
#include "iostream"
#include "Console.h"
#include <fstream>
#include <string>
using namespace std;
class Logger
{
public:
	Console b;
	ofstream file;
	Logger();
	void open(const string& filename);
	void close();
	void write(const Console& console);

private:
};