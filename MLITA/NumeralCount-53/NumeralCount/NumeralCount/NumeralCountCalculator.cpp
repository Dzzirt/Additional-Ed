#include "stdafx.h"
#include "NumeralCountCalculator.h"

using namespace std;

unsigned long long CNumeralCountCalculator::Calculate(std::string const& from, std::string const& to)
{
	if (from.size() == to.size())
	{
		return (stoull(to) - stoull(from) + 1) * from.size();
	}
	auto loweredDischarge = static_cast<unsigned long long>(pow(10, to.size() - 1)) - 1;
	auto previousDishargeCount = Calculate(from, to_string(loweredDischarge));
	auto currentDishargeNumeralCount = (stoull(to) - loweredDischarge) * to.size();
	return currentDishargeNumeralCount + previousDishargeCount;
};

CNumeralCountCalculator::CNumeralCountCalculator(std::string const& input)
{
	ifstream in(input);
	string line;
	getline(in, line);
	vector<string> sourceDigits;
	boost::split(sourceDigits, line, bind2nd(equal_to<char>(), ' '));
	m_from = sourceDigits[0];
	m_to = sourceDigits[1];
}

void CNumeralCountCalculator::WriteInFile(std::string const& output)
{
	ofstream out(output);
	out << Calculate(m_from, m_to);
	out.close();
}
