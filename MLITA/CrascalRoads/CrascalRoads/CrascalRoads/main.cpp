// CrascalRoads.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MinimalRoadCostCalculator.h"

using namespace std;

int main(int argc, char * argv[])
{
if (argc != 3)
	{
		CMinimalRoadCostCalculator calc("input.txt");
		calc.Calculate("output.txt");
	}
	else
	{
		CMinimalRoadCostCalculator calc(argv[1]);
		calc.Calculate(argv[2]);
	}
    return 0;
}

