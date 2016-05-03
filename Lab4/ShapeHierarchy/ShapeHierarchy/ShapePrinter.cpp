#include "stdafx.h"
#include "ShapePrinter.h"
#include <boost/range/algorithm/transform.hpp>
#include <iterator>

using namespace std;

CShapePrinter::CShapePrinter(std::vector<std::shared_ptr<IShape>> const& shapes)
	:m_shapes(shapes)
{

}

void CShapePrinter::PrintSortedByAreaIncreasing()
{
	auto sorted = m_shapes;
	cout << "Sorted by area increasing :" << endl;
	std::sort(sorted.begin(), sorted.end(), [&](std::shared_ptr<IShape> const& ptr1, std::shared_ptr<IShape> const& ptr2)
	{
		return ptr1->GetArea() < ptr2->GetArea();
	});
	for (auto const& shape : sorted)
	{
		cout << shape->ToString();
	}
}

void CShapePrinter::PrintSortedByPerimeterDecreasing()
{
	auto sorted = m_shapes;
	cout << "Sorted by perimeter decreasing :" << endl;
	std::sort(sorted.begin(), sorted.end(), [&](std::shared_ptr<IShape> & ptr1, std::shared_ptr<IShape> & ptr2)
	{
		return ptr1->GetPerimeter() > ptr2->GetPerimeter();
	});
	for (auto const& shape : sorted )
	{
		cout << shape->ToString();
	}
	//boost::transform(sorted, ostream_iterator<shared_ptr<IShape>>(cout, "\n"), ShapeToString);
}

CShapePrinter::~CShapePrinter()
{
}

std::string CShapePrinter::ShapeToString(std::shared_ptr<IShape> & shape)
{
	return shape->ToString();
}
