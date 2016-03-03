// Dictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "fstream"
int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: <dictionary file>" << std::endl;
	}

	std::ifstream in(argv[1]);
	if (in)
	{
	}
	
	return 0;
}

