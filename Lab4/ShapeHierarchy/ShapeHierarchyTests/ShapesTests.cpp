#include "stdafx.h"
#include "../ShapeHierarchy/Point.h"
#include "../ShapeHierarchy/LineSegment.h"
#include "../ShapeHierarchy/Rectangle.h"

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
BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(rectangle_tests, RectangleFixture)
	BOOST_AUTO_TEST_CASE(width_and_height_should_have_positive_values)
	{
		BOOST_CHECK_THROW(CRectangle(CPoint(1, 1), -1, -2), std::invalid_argument);
	}
BOOST_AUTO_TEST_SUITE_END()