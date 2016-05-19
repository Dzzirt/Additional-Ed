#pragma once
#include <array>

struct Point
{
	Point() = default;
	Point(double x, double y) : x(x), y(y) {}
	double x = 0;
	double y = 0;
};

typedef std::array<Point, 3> Triangle;

class CTriangleOwnerPointDefiner
{
public:
	CTriangleOwnerPointDefiner() = delete;
	CTriangleOwnerPointDefiner(Triangle const& triangle, Point const& freePoint);
	~CTriangleOwnerPointDefiner() = default;
	static double GetArea(Point p1, Point p2, Point p3);
	bool IsTriangleBelongsToPoint();
private:
	Triangle m_triangle;
	Point m_freePoint;
};

