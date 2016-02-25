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

void Transform(std::vector<double> &numbers)
{
	auto maxElem = std::max_element(numbers.begin(), numbers.end());
	DevideEachOn(numbers, *maxElem / 2.f);
}
