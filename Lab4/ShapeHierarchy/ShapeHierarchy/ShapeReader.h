#pragma once
#include "Shape.h"
#include <vector>
#include <memory>
#include <iostream>

class CShapeReader
{
public:
	CShapeReader() = delete;
	CShapeReader(std::istream & is);
	void ReadShapes();
	void PrintSortedByAreaIncreasing();
	void PrintSortedByPerimeterDecreasing();
	std::vector<std::shared_ptr<IShape>> GetShapes()const;
private:
	std::istream & m_input;
	std::vector<std::shared_ptr<IShape>> m_shapes;
};

