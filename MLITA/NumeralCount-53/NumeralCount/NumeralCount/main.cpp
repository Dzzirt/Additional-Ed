// NumeralCount.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "NumeralCountCalculator.h"

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		CNumeralCountCalculator calc("input.txt");
		calc.WriteInFile("output.txt");
	}
	else
	{
		CNumeralCountCalculator calc(argv[1]);
		calc.WriteInFile(argv[2]);
	}
    return 0;
}

