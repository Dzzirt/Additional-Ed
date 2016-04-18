// ShapeHierarchy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ShapeReader.h"
#include "ShapeRenderer.h"
#include <fstream>

int main()
{
	std::ifstream in("input.txt");
	CShapeReader reader(in);
	reader.ReadShapes();
	reader.PrintSortedByAreaIncreasing();
	reader.PrintSortedByPerimeterDecreasing();
	CShapeRenderer renderer(reader.GetShapes());
	renderer.Render();
	return 0;
}

