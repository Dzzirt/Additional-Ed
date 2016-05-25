#include "stdafx.h"
#include "../MathUtils.h"
using namespace std;


struct Sportsman
{
	Sportsman(){};
	Sportsman(std::string const &fullName, unsigned height, unsigned weight)
		:fullName(fullName), height(height), weight(weight)
	{

	};
	std::string fullName = "";
	unsigned height = 0;
	unsigned weight = 0;
};

BOOST_AUTO_TEST_SUITE(Find_max_element_function)
	
	BOOST_AUTO_TEST_CASE(guarantees_strong_exception_safety)
	{
		size_t callCount = 0;
	    auto func = [&](auto const& num1, auto const& num2)
		{
			if (callCount == 2)
			{
				throw std::runtime_error("Oh, something wrong...");
			}
			callCount++;
			return num1 < num2;
		};

		int max = 0;
		try
		{
			FindMax({1, 2, 3, 4, 5}, max, func);
		}
		catch (...){};
		BOOST_CHECK(max != 3);
		BOOST_CHECK(max == 0);

	}
	BOOST_AUTO_TEST_CASE(uses_binary_predicate_as_search_strategy)
	{
		std::vector<Sportsman> sportsmen = {
			Sportsman("Милон из Кротона", 165, 71),
			Sportsman("Астил из Кротона", 170, 90),
			Sportsman("Ласфен из Тебеи ", 181, 60),
			Sportsman("Эгей из Аргоса", 181, 79),
			Sportsman("Леонид из Родоса", 179, 90)
		};

		Sportsman highest;
		auto success = FindMax(sportsmen, highest, [&](auto const& s1, auto const& s2)
		{
			return s1.height < s2.height;
		});
		BOOST_CHECK(success);
		BOOST_CHECK(highest.fullName == sportsmen[2].fullName);
		BOOST_CHECK(highest.fullName != sportsmen[3].fullName);

		Sportsman heaviest;
		auto success2 = FindMax(sportsmen, heaviest, [&](auto const& s1, auto const& s2)
		{
			return s1.weight < s2.weight;
		});
		BOOST_CHECK(success2);
		BOOST_CHECK(heaviest.fullName == sportsmen[1].fullName);
		BOOST_CHECK(heaviest.fullName != sportsmen[4].fullName);

		sportsmen.clear();
		Sportsman onEmpty;
		auto tmp = onEmpty;
		auto success3 = FindMax(sportsmen, heaviest, [&](auto const& s1, auto const& s2)
		{
			return s1.weight < s2.weight;
		});
		BOOST_CHECK(!success3);
		BOOST_CHECK(tmp.fullName == onEmpty.fullName);


	}

BOOST_AUTO_TEST_SUITE_END()