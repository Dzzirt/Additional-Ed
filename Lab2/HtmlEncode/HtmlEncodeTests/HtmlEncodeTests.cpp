// HtmlEncodeTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../HtmlEncode/HtmlEncode.h"

BOOST_AUTO_TEST_SUITE(EncodeStringElementsToHtmlEntities)

	BOOST_AUTO_TEST_CASE(EncodeNotEmptyString)
	{
		std::string source = R"(a"bb'c<<d>>e&&&)";
		BOOST_CHECK_EQUAL(HtmlEncode(source), "a&quot;bb&apos;c&lt;&lt;d&dt;&dt;e&amp;&amp;&amp;");
	};
	BOOST_AUTO_TEST_CASE(EncodeEmptyString)
	{
		std::string source = "";
		BOOST_CHECK_EQUAL(HtmlEncode(source), "");
	};

BOOST_AUTO_TEST_SUITE_END()