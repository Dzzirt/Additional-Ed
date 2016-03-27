// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage: lab1.exe commands.json input.json output.txt" << std::endl;
		return 1;
	}

	return 0;
}

