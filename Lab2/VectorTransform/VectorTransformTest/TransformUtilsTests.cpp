#include "stdafx.h"
#include "../VectorTransform/TransformUtils.h"
#include "limits"
#include "cmath"

bool Compare(std::vector<double> const& vec1, std::vector<double> const& vec2)
{
	if (vec1.size() == vec2.size())
	{
		for (size_t i = 0; i < vec1.size(); i++)
		{
			if (vec1[i] != vec1[i] && vec2[i] != vec2[i])
			{
				continue;
			}
			if (vec1[i] != vec2[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

BOOST_AUTO_TEST_SUITE(DevideEachOfVectorOnHalfOfMaxElement)

	BOOST_AUTO_TEST_CASE(WhenVectorSizeMoreThanZero)
	{
		std::vector<double> source = { 2, 2, 2, 2, 4 };
		std::vector<double> rightResult = { 1, 1, 1, 1, 2 };
		source = Transform(source);
		BOOST_CHECK(source == rightResult);
	}
	BOOST_AUTO_TEST_CASE(WhenVectorSizeEqualsZero)
	{
		std::vector<double> source = {};
		std::vector<double> rightResult = {};
		source = Transform(source);
		BOOST_CHECK(source == rightResult);
	}
	BOOST_AUTO_TEST_CASE(WhenMaxElementEqualZero)
	{
		double inf = std::numeric_limits<double>::infinity();
		std::vector<double> source = { -1.0, -2.0, 0.0 };
		std::vector<double> result = {-inf, -inf, -NAN};
		BOOST_CHECK_EQUAL(Compare(result, Transform(source)), true);
	}
	BOOST_AUTO_TEST_CASE(WhenMaxElementIsFirst)
	{
		std::vector<double> source = { 4, 2, 2, 2, 2 };
		std::vector<double> rightResult = { 2, 1, 1, 1, 1 };
		source = Transform(source);
		BOOST_CHECK(source == rightResult);
	}
BOOST_AUTO_TEST_SUITE_END()