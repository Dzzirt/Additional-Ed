// VisualCheckersTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include "../VisualCheckers/OneStepCheckers.h"

BOOST_AUTO_TEST_SUITE(Visual_checkers_tests)
	BOOST_AUTO_TEST_CASE(finds_max_count_of_eaten_black_checkers)
	{
		std::ifstream in("Txt/input.txt");
		std::ifstream in1("Txt/input1.txt"); 
		std::ifstream in2("Txt/input2.txt");
		std::ifstream in3("Txt/input3.txt");
		COneStepCheckers checkers(in);
		COneStepCheckers checkers1(in1);
		COneStepCheckers checkers2(in2);
		COneStepCheckers checkers3(in3);
		BOOST_CHECK(checkers.Run() == 4);
		BOOST_CHECK(checkers1.Run() == 5);
		BOOST_CHECK(checkers2.Run() == 3);
		BOOST_CHECK(checkers3.Run() == 0);
	}
BOOST_AUTO_TEST_SUITE_END()