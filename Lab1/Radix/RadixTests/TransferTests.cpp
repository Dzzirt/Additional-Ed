#include "stdafx.h"
#include "../Radix/Transfer.h"

BOOST_AUTO_TEST_SUITE(RadixTests)

	BOOST_AUTO_TEST_CASE(ToDecimal)
	{
		BOOST_CHECK_EQUAL(ToDecimalNotation("1F", 16), 31);
		BOOST_CHECK_EQUAL(ToDecimalNotation("1111", 2), 15);
		BOOST_CHECK_EQUAL(ToDecimalNotation("-15", 6), -11);
	}
BOOST_AUTO_TEST_CASE(FromDecimal)
{
	BOOST_CHECK_EQUAL(FromDecimalToDestination(1, 2), "1");
	BOOST_CHECK_EQUAL(FromDecimalToDestination(555, 6), "2323");
	BOOST_CHECK_EQUAL(FromDecimalToDestination(-15, 2), "-1111");
}
BOOST_AUTO_TEST_CASE(TransferTest)
{
	BOOST_CHECK_EQUAL(Transfer(3, 16, "-20"), "-6");
	BOOST_CHECK_EQUAL(Transfer(16, 25, "909"), "3HD");
	BOOST_CHECK_EQUAL(Transfer(30, 26, "-JJJ"), "-1049");
	BOOST_CHECK_EQUAL(Transfer(34, 33, "2147483647"), "2LPDRIU19D");
	BOOST_CHECK_EQUAL(Transfer(34, 16, "-2147483648"), "-7044D1BEC200");
	BOOST_CHECK_EQUAL(Transfer(2, 3, "-0"), "0");
}
BOOST_AUTO_TEST_SUITE_END()