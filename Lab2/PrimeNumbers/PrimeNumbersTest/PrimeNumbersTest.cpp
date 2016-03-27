// PrimeNumbersTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../PrimeNumbers/PrimeNumbersUtils.h"

BOOST_AUTO_TEST_SUITE(PrimeNumbersTests)

	BOOST_AUTO_TEST_CASE(GenerateCorrectResultIfLastNumIsPrime)
	{
		std::set<int> upperBound19 = { 2, 3, 5, 7, 11, 13, 17, 19 };
		std::set<int> primeNumbers = GeneratePrimeNumbersSet(19);
		BOOST_CHECK(primeNumbers == upperBound19);
	}

	BOOST_AUTO_TEST_CASE(GenerateCorrectResultIfLastNumIsNotPrime)
	{
		std::set<int> upperBound18 = { 2, 3, 5, 7, 11, 13, 17};
		std::set<int> primeNumbers = GeneratePrimeNumbersSet(18);
		BOOST_CHECK(primeNumbers == upperBound18);
	}

	BOOST_AUTO_TEST_CASE(GenerateCorrectResultIfLastNumIs2)
	{
		std::set<int> upperBound2 = {2};
		std::set<int> primeNumbers = GeneratePrimeNumbersSet(2);
		BOOST_CHECK(primeNumbers == upperBound2);
	}

	BOOST_AUTO_TEST_CASE(GenerateCorrectResultIfLastIs1)
	{
		std::set<int> upperBound2 = {};
		std::set<int> primeNumbers = GeneratePrimeNumbersSet(1);
		BOOST_CHECK(primeNumbers == upperBound2);
	}

BOOST_AUTO_TEST_SUITE_END()


