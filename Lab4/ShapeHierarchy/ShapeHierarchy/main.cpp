// ShapeHierarchy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ShapeManager.h"
#include <fstream>

int main()
{
	CShapeManager manager(std::cin);
	manager.Print();
	manager.Render();
	return 0;
}

