// TriangleAndPoint.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Application.h"


int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		CApplication app("input.txt");
		app.WriteResult("output.txt");
	}
	else
	{
		CApplication app(argv[1]);
		app.WriteResult(argv[2]);
	}
	return 0;
}

