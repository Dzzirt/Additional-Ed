// VecTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


BOOST_AUTO_TEST_CASE(EverythingIsOK)
{
	BOOST_CHECK_EQUAL(2 * 2, 4);
}
