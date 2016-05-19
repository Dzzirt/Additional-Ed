// TriangleAndPointTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../TriangleAndPoint/TriangleOwnerPointDefiner.h"

BOOST_AUTO_TEST_SUITE(testing)
BOOST_AUTO_TEST_CASE(the_correctness_of_the_result_of_the_area_calculation)
{
	BOOST_CHECK(CTriangleOwnerPointDefiner::GetArea(Point{ 1, 1 }, Point{ 1, 3 }, Point{ 7, 2 })
		== 6);
	BOOST_CHECK(CTriangleOwnerPointDefiner::GetArea(Point{ -5, 1 }, Point{ 2, 3 }, Point{ 5, 2 })
		== 6.5);
	BOOST_CHECK(CTriangleOwnerPointDefiner::GetArea(Point{ 1, 1 }, Point{ 2, 5 }, Point{ 7, -7 })
		== 16);
	BOOST_CHECK(CTriangleOwnerPointDefiner::GetArea(Point{ 5, 5 }, Point{ 5, 10 }, Point{ 10, 5 })
		== 12.5);
	BOOST_CHECK(CTriangleOwnerPointDefiner::GetArea(Point{ -5, -5 }, Point{ -4, 1 }, Point{ -3, -5 })
		== 6);
	BOOST_CHECK(CTriangleOwnerPointDefiner::GetArea(Point{ 0, 0 }, Point{ 0, 0 }, Point{ 0, 0 })
		== 0);
	BOOST_CHECK(CTriangleOwnerPointDefiner::GetArea(Point{ 0, 0 }, Point{ 0, 0 }, Point{ 100, 20 })
		== 0);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(triangle_belongs_point)
	BOOST_AUTO_TEST_CASE(which_coincides_with_vertex)
	{
		CTriangleOwnerPointDefiner def({ Point{1, 1}, Point{1, 3}, Point{7, 2} }, Point{1, 1});
		BOOST_CHECK(def.IsTriangleBelongsToPoint());
		CTriangleOwnerPointDefiner def2({ Point{ 5, 5 }, Point{ 5, 10 }, Point{ 10, 5 } }, Point{ 5, 10 });
		BOOST_CHECK(def2.IsTriangleBelongsToPoint());
		CTriangleOwnerPointDefiner def3({ Point{ -5, -5 }, Point{ -4, 1 }, Point{ -3, -5 } }, Point{ -3, -5 });
		BOOST_CHECK(def3.IsTriangleBelongsToPoint());

		CTriangleOwnerPointDefiner def4({ Point{ -5, -5 }, Point{ -4, 1 }, Point{ -3, -5 } }, Point{ 0, 0 });
		BOOST_CHECK(!def4.IsTriangleBelongsToPoint());
	}

	BOOST_AUTO_TEST_CASE(which_belongs_to_side_of_triangle)
	{
		CTriangleOwnerPointDefiner def( { Point{ 5, 5 }, Point{ 5, 10 }, Point{ 10, 5 } }, Point{5 , 7});
		BOOST_CHECK(def.IsTriangleBelongsToPoint());
		CTriangleOwnerPointDefiner def2({ Point{ 5, 5 }, Point{ 5, 10 }, Point{ 10, 5 } }, Point{ 7 , 5 });
		BOOST_CHECK(def.IsTriangleBelongsToPoint());
		CTriangleOwnerPointDefiner def3({ Point{ 5, 5 }, Point{ 5, 10 }, Point{ 10, 5 } }, Point{ 7.5, 7.5 });
		BOOST_CHECK(def.IsTriangleBelongsToPoint());
	}
BOOST_AUTO_TEST_SUITE_END()

