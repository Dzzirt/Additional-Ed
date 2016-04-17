// ShapeHierarchy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ShapeReader.h"
#include <fstream>
int main()
{
	auto in = std::ifstream("input.txt");
	CShapeReader reader(in);
	reader.ReadShapes();
	reader.PrintSortedByAreaIncreasing();
	reader.PrintSortedByPerimeterDecreasing();
	return 0;
}

