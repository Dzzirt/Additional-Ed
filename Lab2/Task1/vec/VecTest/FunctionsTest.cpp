#include "stdafx.h"
#include "../vec/functions.h"

BOOST_AUTO_TEST_SUITE(FunctionsTest)

BOOST_AUTO_TEST_CASE(CheckDigit)
{
	BOOST_CHECK_EQUAL(is_digits("24"), true);
}

BOOST_AUTO_TEST_SUITE_END()
