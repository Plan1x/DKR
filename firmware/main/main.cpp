// Dkr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Console.h"
#include "Vector.h"
#include "Logger.h"

	using namespace std;
	int main()
	{
		Logger log;
		Console a;
		log.open("log.txt");
		while (1)
		{
				a.application();			
				if (a.flag_for_clear)// flag for clearing all
				{
					log.write(a);
					break;
					
				}
		}
				
			delete[] a.p_arr;
			log.close();
		
		return main();
	}


