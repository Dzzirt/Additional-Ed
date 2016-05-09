#include "stdafx.h"
#include "TriangleOwnerPointDefiner.h"

using namespace std;

CTriangleOwnerPointDefiner::CTriangleOwnerPointDefiner(std::string const& input)
{
	ReadInput(input);
}

void CTriangleOwnerPointDefiner::WriteResult(std::string const& output)
{
	ofstream out(output);
	IsTriangleBelongToPoint() ? out << "In" << endl : out << "Out" << endl;
	out.close();
}

void CTriangleOwnerPointDefiner::ReadInput(std::string const& input)
{
	ifstream in(input);
	int x;
	int y;
	in >> x >> y;
	m_freePoint = { x, y };
	for (size_t i = 0; i < 3; i++)
	{
		in >> x >> y;
		m_triangle[i] = { x, y };
	}
}

bool CTriangleOwnerPointDefiner::IsTriangleBelongToPoint()
{
	auto triangleArea = GetArea(m_triangle[0], m_triangle[1], m_triangle[2]);
	auto part1 = abs(GetArea(m_triangle[0], m_triangle[1], m_freePoint));
	auto part2 = abs(GetArea(m_triangle[2], m_triangle[1], m_freePoint));
	auto part3 = abs(GetArea(m_triangle[0], m_triangle[2], m_freePoint));
	return triangleArea == part1 + part2 + part3;
}

double CTriangleOwnerPointDefiner::GetArea(Point p1, Point p2, Point p3)
{
	return 0.5f * ((p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y));
}