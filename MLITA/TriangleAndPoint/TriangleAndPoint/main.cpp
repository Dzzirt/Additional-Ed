// TriangleAndPoint.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TriangleOwnerPointDefiner.h"


int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		CTriangleOwnerPointDefiner top("input.txt");
		top.WriteResult("output.txt");
	}
	else
	{
		CTriangleOwnerPointDefiner top(argv[1]);
		top.WriteResult(argv[2]);
	}
	return 0;
}

