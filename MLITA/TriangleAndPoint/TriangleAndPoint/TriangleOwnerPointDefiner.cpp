#include "stdafx.h"
#include "TriangleOwnerPointDefiner.h"

using namespace std;

CTriangleOwnerPointDefiner::CTriangleOwnerPointDefiner(Triangle const& triangle, Point const& freePoint)
	:m_triangle(triangle), m_freePoint(freePoint)
{
}

bool CTriangleOwnerPointDefiner::IsTriangleBelongsToPoint()
{
	auto triangleArea = GetArea(m_triangle[0], m_triangle[1], m_triangle[2]);
	auto part1 = GetArea(m_triangle[0], m_triangle[1], m_freePoint);
	auto part2 = GetArea(m_triangle[2], m_triangle[1], m_freePoint);
	auto part3 = GetArea(m_triangle[0], m_triangle[2], m_freePoint);
	return triangleArea == part1 + part2 + part3;
}

double CTriangleOwnerPointDefiner::GetArea(Point p1, Point p2, Point p3)
{
	return abs(0.5f * ((p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y)));
}