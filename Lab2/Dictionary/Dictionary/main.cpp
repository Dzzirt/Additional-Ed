// Dictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DictUtils.h"
#include <windows.h>

using namespace std;



int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Usage: <dictionary file>" << std::endl;
	}
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	string filename = argv[1];
	OpenDictionary(filename);
	return 0;
}

