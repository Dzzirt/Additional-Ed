#pragma once
#include "Shape.h"

class CShapePrinter
{
public:
	CShapePrinter() = delete;
	CShapePrinter(std::vector<std::shared_ptr<IShape>> const& shapes);
	void PrintSortedByAreaIncreasing();
	void PrintSortedByPerimeterDecreasing();
	~CShapePrinter();
private:
	std::vector<std::shared_ptr<IShape>> m_shapes;
};

