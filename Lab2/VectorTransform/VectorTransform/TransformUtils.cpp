#include "stdafx.h"
#include "TransformUtils.h"

using namespace boost::phoenix::placeholders;
using namespace std;

std::vector<double> ReadInVector()
{
	return{ std::istream_iterator<double>(std::cin), (std::istream_iterator<double>()) };
}

void DevideEachOn(std::vector<double> & numbers, double value)
{
	boost::transform(numbers, numbers.begin(), arg1 / value);
}

void Sort(std::vector<double> & numbers)
{
	std::sort(numbers.begin(), numbers.end());
}

void PrintSeparatedByComma(std::vector<double> const& numbers)
{
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(cout, ", "));
}

std::vector<double> Transform(std::vector<double> const&numbers)
{
	auto result = numbers;
	if (numbers.size() != 0)
	{
		auto maxElem = std::max_element(result.begin(), result.end());
		DevideEachOn(result, *maxElem / 2.f);
	}
	return result;
}


