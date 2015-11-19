#include "stdafx.h"
#include "../vec/functions.h"

BOOST_AUTO_TEST_SUITE(FunctionsTest)

BOOST_AUTO_TEST_CASE(CheckFunctions)
{
	BOOST_CHECK_EQUAL(IsDigits("24"), true);
	BOOST_CHECK_EQUAL(IsDigitValues({ "1", "2", "3" }), true);
}

BOOST_AUTO_TEST_SUITE_END()
