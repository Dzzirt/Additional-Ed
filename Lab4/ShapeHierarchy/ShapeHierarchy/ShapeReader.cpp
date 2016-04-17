#include "stdafx.h"
#include "ShapeReader.h"
#include "Rectangle.h"
#include "LineSegment.h"
#include "Triangle.h"
#include "Circle.h"
#include <boost/algorithm/string.hpp>

using namespace std;

CShapeReader::CShapeReader(std::istream & is)
	:m_input(is)
{
}

void CShapeReader::ReadShapes()
{
	while (!m_input.eof() && !m_input.fail())
	{
		string str;
		vector<string> splitted;
		getline(m_input, str);
		boost::split(splitted, str, bind2nd(equal_to<char>(), ' '));
		if (splitted[0] == "Rectangle")
		{
			vector<string> pos;
			boost::split(pos, splitted[1], bind2nd(equal_to<char>(), ';'));
			auto width = stod(splitted[2]);
			auto height = stod(splitted[3]);
			auto upperLeft = CPoint(stod(pos[0]), stod(pos[1]));
			auto rect = std::make_shared<CRectangle>(upperLeft, width, height);
			rect->SetFillColor(splitted[4]);
			rect->SetBorderColor(splitted[5]);
			m_shapes.push_back(rect);
		}
		else if (splitted[0] == "Line")
		{
			vector<string> first;
			vector<string> second;
			boost::split(first, splitted[1], bind2nd(equal_to<char>(), ';'));
			boost::split(second, splitted[2], bind2nd(equal_to<char>(), ';'));
			auto firstPoint = CPoint(stod(first[0]), stod(first[1]));
			auto secondPoint = CPoint(stod(second[0]), stod(second[1]));
			auto line = std::make_shared<CLineSegment>(firstPoint, secondPoint);
			line->SetBorderColor(splitted[3]);
			m_shapes.push_back(line);
		}
		else if (splitted[0] == "Triangle")
		{
			vector<string> vertex1;
			vector<string> vertex2;
			vector<string> vertex3;
			boost::split(vertex1, splitted[1], bind2nd(equal_to<char>(), ';'));
			boost::split(vertex2, splitted[2], bind2nd(equal_to<char>(), ';'));
			boost::split(vertex3, splitted[3], bind2nd(equal_to<char>(), ';'));
			auto firstVertex = CPoint(stod(vertex1[0]), stod(vertex1[1]));
			auto secondVertex = CPoint(stod(vertex2[0]), stod(vertex2[1]));
			auto thirdVertex = CPoint(stod(vertex3[0]), stod(vertex3[1]));
			auto triangle = std::make_shared<CTriangle>(firstVertex, secondVertex, thirdVertex);
			triangle->SetFillColor(splitted[4]);
			triangle->SetBorderColor(splitted[5]);
			m_shapes.push_back(triangle);
		}
		else if (splitted[0] == "Circle")
		{
			vector<string> center;
			boost::split(center, splitted[1], bind2nd(equal_to<char>(), ';'));
			auto radius = splitted[2];
			auto centerPos = CPoint(stod(center[0]), stod(center[1]));
			auto circle = std::make_shared<CCircle>(centerPos, stod(radius));
			circle->SetFillColor(splitted[3]);
			circle->SetBorderColor(splitted[4]);
			m_shapes.push_back(circle);
		}
	}
}

void CShapeReader::PrintSortedByAreaIncreasing()
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

void CShapeReader::PrintSortedByPerimeterDecreasing()
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
