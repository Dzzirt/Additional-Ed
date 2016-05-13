#pragma once

struct Point
{
	Point() = default;
	Point(int x, int y) : x(x), y(y) {}
	int x = 0;
	int y = 0;
};

class CTriangleOwnerPointDefiner
{
public:
	CTriangleOwnerPointDefiner() = delete;
	CTriangleOwnerPointDefiner(std::string const& input);
	~CTriangleOwnerPointDefiner() = default;
	void WriteResult(std::string const& output);
private:
	void ReadInput(std::string const& input);
	bool IsTriangleBelongsToPoint();
	double GetArea(Point p1, Point p2, Point p3);
	std::array<Point, 3> m_triangle;
	Point m_freePoint;
};

