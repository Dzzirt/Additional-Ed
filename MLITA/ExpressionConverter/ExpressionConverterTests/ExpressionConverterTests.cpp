// ExpressionConverterTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../ExpressionConverter/ExpressionConverter.h"

struct ConverterFixture
{
	CExpressionConverter converter;
};

BOOST_FIXTURE_TEST_SUITE(expression_converter, ConverterFixture)

BOOST_AUTO_TEST_CASE(ignores_the_whitespaces)
{
	auto output = converter.ToSuffixNotation("       5     *3 +6/3    /2");
	BOOST_CHECK_EQUAL(output, "5 3 * 6 3 / 2 / +");
	auto outputEmpty = converter.ToSuffixNotation("");
	BOOST_CHECK_EQUAL(outputEmpty, "");
}

BOOST_AUTO_TEST_CASE(throws_error_if_not_enougth_matching_parentheses)
{
	BOOST_CHECK_THROW(converter.ToSuffixNotation("2 + 10 * (1 + 2 * 3 / 2 + 3 - 2"),
		std::invalid_argument);
}
BOOST_AUTO_TEST_SUITE_END()

