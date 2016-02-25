#include "stdafx.h"
#include "../VectorTransform/TransformUtils.h"

BOOST_AUTO_TEST_SUITE(TransformUtilsTest)

	BOOST_AUTO_TEST_CASE(DevideEachOfVectorOnHalfOfMaxElement)
{
	std::vector<double> source = { 2, 2, 2, 2, 4 };
	std::vector<double> rightResult = { 1, 1, 1, 1, 2 };
	Transform(source);
	BOOST_CHECK(source == rightResult);
};
BOOST_AUTO_TEST_SUITE_END()