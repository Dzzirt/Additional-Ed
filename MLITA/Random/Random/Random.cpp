// Random.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <fstream>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	ofstream out("input.txt");
	for (size_t i = 0; i < 200000; i++)
	{
		out << (rand() % 1000000000000 + 1) * pow(-1, i) << " " ;
	}
	return 0;
}

