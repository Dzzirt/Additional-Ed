// Invert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "InvertMatrix.h"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: invert.exe <input file with 3x3 matrix>" << std::endl;
		return 1;
	}
	std::string fileName = argv[1];
	try
	{
		PrintMatrix(Invert3dMatrix(Get3dMatrixFromFile(fileName)));
	}
	catch (std::invalid_argument const& err)
	{
		std::cout << err.what() << std::endl;
		return 1;
	}
	return 0;
}

