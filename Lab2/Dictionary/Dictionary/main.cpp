// Dictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include "Dictionary.h"
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
	Dictionary dict(filename);
	dict.InteractWithUser();
	return 0;
}

