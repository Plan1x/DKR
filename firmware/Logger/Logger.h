#pragma once
#include "iostream"
#include <fstream>
#include <string>
#include "AES_Coding.h"
using namespace std;

class Logger
{
public:
	
	
	
	Logger();
	void open(const string& filename);
	void close();
	void write(const string& out);
	void write_encrypt_data(const Aes& data);
	void read_data(const string& filename);
	string test;
private:

	ifstream infile;
	ofstream file;
};