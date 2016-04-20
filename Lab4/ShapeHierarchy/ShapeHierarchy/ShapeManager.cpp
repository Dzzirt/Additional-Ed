#include "stdafx.h"
#include "ShapeManager.h"
#include "Rectangle.h"
#include "LineSegment.h"
#include "Triangle.h"
#include "Circle.h"
#include <boost/algorithm/string.hpp>
#include "ShapePrinter.h"
#include "ShapeRenderer.h"

using namespace std;

CShapeManager::CShapeManager(std::istream & is)
	:m_input(is)
{
	LoadShapes();
}

void CShapeManager::Render()
{
	CShapeRenderer renderer(m_shapes);
	renderer.Render();
}

void CShapeManager::Print()
{
	CShapePrinter printer(m_shapes);
	printer.PrintSortedByAreaIncreasing();
	printer.PrintSortedByPerimeterDecreasing();
}

void CShapeManager::LoadShapes()
{
	string str;
	while (getline(m_input, str))
	{
		vector<string> splitted;
		boost::split(splitted, str, bind2nd(equal_to<char>(), ' '));
		m_shapes.push_back(CreateShape(splitted));
	}
}

std::shared_ptr<IShape> CShapeManager::CreateShape(std::vector<std::string> const& shapeInfo)
{
	std::shared_ptr<IShape> shape;
	if (shapeInfo[0] == "Rectangle")
	{
		vector<string> pos;
		boost::split(pos, shapeInfo[1], bind2nd(equal_to<char>(), ';'));
		auto width = stod(shapeInfo[2]);
		auto height = stod(shapeInfo[3]);
		auto upperLeft = CPoint(stod(pos[0]), stod(pos[1]));
		auto rect = std::make_shared<CRectangle>(upperLeft, width, height);
		vector<string> fill;
		boost::split(fill, shapeInfo[4], bind2nd(equal_to<char>(), ':'));
		rect->SetFillColor(CColorRGB(stoi(fill[0]), stoi(fill[1]), stoi(fill[2])));
		vector<string> border;
		boost::split(border, shapeInfo[5], bind2nd(equal_to<char>(), ':'));
		rect->SetBorderColor(CColorRGB(stoi(border[0]), stoi(border[1]), stoi(border[2])));
		shape = move(rect);
	}
	else if (shapeInfo[0] == "Line")
	{
		vector<string> first;
		vector<string> second;
		boost::split(first, shapeInfo[1], bind2nd(equal_to<char>(), ';'));
		boost::split(second, shapeInfo[2], bind2nd(equal_to<char>(), ';'));
		auto firstPoint = CPoint(stod(first[0]), stod(first[1]));
		auto secondPoint = CPoint(stod(second[0]), stod(second[1]));
		auto line = std::make_shared<CLineSegment>(firstPoint, secondPoint);
		vector<string> border;
		boost::split(border, shapeInfo[3], bind2nd(equal_to<char>(), ':'));
		line->SetBorderColor(CColorRGB(stoi(border[0]), stoi(border[1]), stoi(border[2])));
		shape = move(line);
	}
	else if (shapeInfo[0] == "Triangle")
	{
		vector<string> vertex1;
		vector<string> vertex2;
		vector<string> vertex3;
		boost::split(vertex1, shapeInfo[1], bind2nd(equal_to<char>(), ';'));
		boost::split(vertex2, shapeInfo[2], bind2nd(equal_to<char>(), ';'));
		boost::split(vertex3, shapeInfo[3], bind2nd(equal_to<char>(), ';'));
		auto firstVertex = CPoint(stod(vertex1[0]), stod(vertex1[1]));
		auto secondVertex = CPoint(stod(vertex2[0]), stod(vertex2[1]));
		auto thirdVertex = CPoint(stod(vertex3[0]), stod(vertex3[1]));
		auto triangle = std::make_shared<CTriangle>(firstVertex, secondVertex, thirdVertex);
		vector<string> fill;
		boost::split(fill, shapeInfo[4], bind2nd(equal_to<char>(), ':'));
		triangle->SetFillColor(CColorRGB(stoi(fill[0]), stoi(fill[1]), stoi(fill[2])));
		vector<string> border;
		boost::split(border, shapeInfo[5], bind2nd(equal_to<char>(), ':'));
		triangle->SetBorderColor(CColorRGB(stoi(border[0]), stoi(border[1]), stoi(border[2])));
		shape = move(triangle);
	}
	else if (shapeInfo[0] == "Circle")
	{
		vector<string> center;
		boost::split(center, shapeInfo[1], bind2nd(equal_to<char>(), ';'));
		auto radius = shapeInfo[2];
		auto centerPos = CPoint(stod(center[0]), stod(center[1]));
		auto circle = std::make_shared<CCircle>(centerPos, stod(radius));
		vector<string> fill;
		boost::split(fill, shapeInfo[3], bind2nd(equal_to<char>(), ':'));
		circle->SetFillColor(CColorRGB(stoi(fill[0]), stoi(fill[1]), stoi(fill[2])));
		vector<string> border;
		boost::split(border, shapeInfo[4], bind2nd(equal_to<char>(), ':'));
		circle->SetBorderColor(CColorRGB(stoi(border[0]), stoi(border[1]), stoi(border[2])));
		shape = move(circle);
	}
	return shape;
}