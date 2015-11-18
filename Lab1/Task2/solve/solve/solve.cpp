// solve.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		cout << "Usage:\nsolve.exe <A> <B> <C>\n" << endl;
		return -1;
	}
	if (!isdigit(*argv[1]) || !isdigit(*argv[2]) || !isdigit(*argv[3])) {
		cout << "<A> <B> <C> must have a digit value" << endl;
		return -1;
	}
	float A = atof(argv[1]);
	float B = atof(argv[2]);
	float C = atof(argv[3]);
	float discriminant = B * B - 4 * A * C;
	if (discriminant < 0)
	{
		cout << "There is not real root" << endl;
	}
	else if (discriminant == 0)
	{
		float x = -B / (2 * A);
		cout << x << endl;
	}
	else
	{
		float x1 = roundf((-B + sqrt(discriminant)) / (2 * A) * 10000) / 10000.f;
		float x2 = roundf((-B - sqrt(discriminant)) / (2 * A) * 10000) / 10000.f;
		cout << x1 << " " << x2 << endl;
	}
	return 0;
}
