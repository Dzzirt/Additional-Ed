// CrascalRoads.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MinimalRoadCostCalculator.h"

using namespace std;

int main(int argc, char * argv[])
{
	string inputFileName = argv[1];
	string outputFileName = argv[2];
	CMinimalRoadCostCalculator calc(inputFileName);
	calc.Calculate(outputFileName);
    return 0;
}

