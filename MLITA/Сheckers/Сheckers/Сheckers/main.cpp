// Ñheckers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "OneStepCheckers.h"

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		COneStepCheckers checkers("input.txt");
		checkers.WriteStepResultInFile("output.txt");
	}
	else
	{
		COneStepCheckers checkers(argv[1]);
		checkers.WriteStepResultInFile(argv[2]);
	}
    return 0;
}

