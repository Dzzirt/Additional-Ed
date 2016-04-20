#include "stdafx.h"
#include "ShapePrinter.h"

using namespace std;

CShapePrinter::CShapePrinter(std::vector<std::shared_ptr<IShape>> const& shapes)
	:m_shapes(shapes)
{

}

void CShapePrinter::PrintSortedByAreaIncreasing()
{
	auto sorted = m_shapes;
	cout << "Sorted by area increasing :" << endl;
	std::sort(sorted.begin(), sorted.end(), [&](std::shared_ptr<IShape> & ptr1, std::shared_ptr<IShape> & ptr2)
	{
		return ptr1->GetArea() < ptr2->GetArea();
	});
	for_each(sorted.begin(), sorted.end(), [&](std::shared_ptr<IShape> & ptr)
	{
		cout << ptr->ToString() << endl;
	});
}

void CShapePrinter::PrintSortedByPerimeterDecreasing()
{
	auto sorted = m_shapes;
	cout << "Sorted by perimeter decreasing :" << endl;
	std::sort(sorted.begin(), sorted.end(), [&](std::shared_ptr<IShape> & ptr1, std::shared_ptr<IShape> & ptr2)
	{
		return ptr1->GetPerimeter() > ptr2->GetPerimeter();
	});
	for_each(sorted.begin(), sorted.end(), [&](std::shared_ptr<IShape> & ptr)
	{
		cout << ptr->ToString() << endl;
	});
}

CShapePrinter::~CShapePrinter()
{
}
