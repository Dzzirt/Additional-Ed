// Invert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "InvertMatrix.h"


int main(int argc, char* argv[])
{
	std::string fileName = argv[1];
	PrintMatrix(Invert3dMatrix(Get3dMatrixFromFile(fileName)));
	return 0;
}

