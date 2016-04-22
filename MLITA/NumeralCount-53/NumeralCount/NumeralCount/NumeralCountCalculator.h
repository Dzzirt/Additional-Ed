#pragma once


class CNumeralCountCalculator
{
public:
	CNumeralCountCalculator() = delete;
	CNumeralCountCalculator(std::string const& input);
	void WriteInFile(std::string const& output);
private:
	unsigned long long Calculate(std::string const& from, std::string const& to);

	std::string m_from;
	std::string m_to;
};