#include "stdafx.h"
#include "../ShapeHierarchy/Point.h"
#include "../ShapeHierarchy/LineSegment.h"
#include "../ShapeHierarchy/Rectangle.h"
#include "../ShapeHierarchy/Triangle.h"

struct PointFixture
{
	CPoint point;

	PointFixture()
		:point(10, 20)
	{

	}
};

struct LineFixture
{
	CLineSegment line;

	LineFixture()
		: line(CPoint(1, 1), CPoint(3, 3))
	{

	}
};

struct RectangleFixture
{
	CRectangle rect;

	RectangleFixture()
		: rect(CPoint(10, 10), 20, 20)
	{

	}
};


BOOST_FIXTURE_TEST_SUITE(point_tests, PointFixture)

	BOOST_AUTO_TEST_CASE(area_and_perimeter_has_zero_value)
	{
		BOOST_CHECK_EQUAL(point.GetArea(), 0);
		BOOST_CHECK_EQUAL(point.GetPerimeter(), 0);
	}
	BOOST_AUTO_TEST_CASE(can_set_position)
	{
		point.SetPosition(20, 30);
		auto new_pos = Vector2Double(20, 30);
		BOOST_CHECK(point.GetPosition() == new_pos);
	}
BOOST_AUTO_TEST_SUITE_END()


BOOST_FIXTURE_TEST_SUITE(line_segment_tests, LineFixture)

	BOOST_AUTO_TEST_CASE(area_has_zero_value)
	{
		BOOST_CHECK_EQUAL(line.GetArea(), 0);
	}

	BOOST_AUTO_TEST_CASE(distance_between_2_points_is_line_length)
	{
		BOOST_CHECK_EQUAL(line.GetPerimeter(), 2.8284271247461903);
	}

	BOOST_AUTO_TEST_CASE(can_get_points)
	{
		CPoint point1(1, 1);
		CPoint point2(3, 3);
		BOOST_CHECK(line.GetFirstPoint().GetPosition() == point1.GetPosition());
		BOOST_CHECK(line.GetSecondPoint().GetPosition() == point2.GetPosition());
	}

BOOST_AUTO_TEST_SUITE_END()


BOOST_FIXTURE_TEST_SUITE(rectangle_tests, RectangleFixture)
	
	BOOST_AUTO_TEST_CASE(width_and_height_should_have_positive_values)
	{
		BOOST_CHECK_THROW(CRectangle(CPoint(1, 1), -1, -2), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(can_get_area)
	{
		BOOST_CHECK(rect.GetArea() == 400);
		CRectangle rect2(CPoint(0, 0), 10, 10);
		BOOST_CHECK(rect2.GetArea() == 100);
	}
	BOOST_AUTO_TEST_CASE(can_get_perimeter)
	{
		BOOST_CHECK(rect.GetPerimeter() == 80);
		CRectangle rect2(CPoint(0, 0), 10, 10);
		BOOST_CHECK(rect2.GetPerimeter() == 40);
	}
	BOOST_AUTO_TEST_CASE(can_get_width)
	{
		BOOST_CHECK(rect.GetWidth() == 20);
		CRectangle rect2(CPoint(0, 0), 10, 30);
		BOOST_CHECK(rect2.GetWidth() == 10);
	}
	BOOST_AUTO_TEST_CASE(can_get_height)
	{
		BOOST_CHECK(rect.GetHeight() == 20);
		CRectangle rect2(CPoint(0, 0), 20, 10);
		BOOST_CHECK(rect2.GetHeight() == 10);
	}

	BOOST_AUTO_TEST_CASE(can_get_position)
	{
		BOOST_CHECK(rect.GetPosition() == Vector2Double(10, 10));
		CRectangle rect2(CPoint(0, 0), 20, 10);
		BOOST_CHECK(rect2.GetPosition() == Vector2Double(0, 0));
	}

BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE(border_color_tests)
	BOOST_AUTO_TEST_CASE(can_set_and_get_border_color)
	{
		CBorderColor borderColor;
		CColorRGB color(100, 100, 100);
		borderColor.SetBorderColor(color);
		BOOST_CHECK(borderColor.GetBorderColor() == color);
	}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(fill_color_tests)
	BOOST_AUTO_TEST_CASE(can_set_and_get_fill_color)
	{
		CFillColor fillColor;
		CColorRGB color(100, 100, 100);
		fillColor.SetFillColor(color);
		BOOST_CHECK(fillColor.GetFillColor() == color);
	}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(triangle_tests)

	BOOST_AUTO_TEST_CASE(can_get_area)
	{
		CTriangle triangle(CPoint(0, 0), CPoint(0, 0), CPoint(0, 0));
		BOOST_CHECK(triangle.GetArea() == 0);

		CTriangle triangle2(CPoint(0, 0), CPoint(10, 10), CPoint(20, 0));
		BOOST_CHECK(triangle2.GetArea() == 100.00000000000001);
	}

	BOOST_AUTO_TEST_CASE(can_get_perimeter)
	{
		CTriangle triangle(CPoint(0, 0), CPoint(0, 0), CPoint(0, 0));
		BOOST_CHECK(triangle.GetPerimeter() == 0);

		CTriangle triangle2(CPoint(0, 0), CPoint(10, 10), CPoint(20, 0));
		BOOST_CHECK(triangle2.GetPerimeter() == 48.284271247461902);
	}

	BOOST_AUTO_TEST_CASE(can_get_borders)
	{
		CTriangle triangle(CPoint(0, 0), CPoint(0, 0), CPoint(0, 0));
		BOOST_CHECK(triangle.GetBaseLine() == CLineSegment(CPoint(0, 0), CPoint(0, 0)));
		BOOST_CHECK(triangle.GetLeftEdge() == CLineSegment(CPoint(0, 0), CPoint(0, 0)));
		BOOST_CHECK(triangle.GetRightEdge() == CLineSegment(CPoint(0, 0), CPoint(0, 0)));

		CTriangle triangle2(CPoint(0, 0), CPoint(10, 10), CPoint(20, 0));
		BOOST_CHECK(triangle2.GetBaseLine() == CLineSegment(CPoint(0, 0), CPoint(20, 0)));
		BOOST_CHECK(triangle2.GetLeftEdge() == CLineSegment(CPoint(0, 0), CPoint(10, 10)));
		BOOST_CHECK(triangle2.GetRightEdge() == CLineSegment(CPoint(10, 10), CPoint(20, 0)));
	}

	BOOST_AUTO_TEST_CASE(can_get_vertexes)
	{
		CTriangle triangle(CPoint(0, 0), CPoint(0, 0), CPoint(0, 0));
		BOOST_CHECK(triangle.GetMiddleVertex() == CPoint(0, 0));
		BOOST_CHECK(triangle.GetRightVertex() == CPoint(0, 0));
		BOOST_CHECK(triangle.GetLeftVertex() == CPoint(0, 0));

		CTriangle triangle2(CPoint(0, 0), CPoint(10, 10), CPoint(0, 20));
		BOOST_CHECK(triangle2.GetMiddleVertex() == CPoint(10, 10));
		BOOST_CHECK(triangle2.GetRightVertex() == CPoint(0, 20));
		BOOST_CHECK(triangle2.GetLeftVertex() == CPoint(0, 0));
	}

BOOST_AUTO_TEST_SUITE_END()