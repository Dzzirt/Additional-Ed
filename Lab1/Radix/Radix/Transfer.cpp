#include "stdafx.h"
#include "Transfer.h"
#include <cmath>
using namespace std;

const int AsciiNumDifference = 55;

std::string Transfer(int sourceNotation, int destNotaion, const std::string & value)
{
	if (value == "0")
	{
		return 0;
	}
	try
	{
		auto decimalVal = ToDecimalNotation(value, sourceNotation);
		string result = FromDecimalToDestination(decimalVal, destNotaion);
		return result;
	}
	catch(invalid_argument err)
	{
		return "";
	}

}

void ValidationOfValue(const std::string &value, int sourceNotation)
{
	for_each(value.begin(), value.end(), [=](char sign)
	{
		if (sign != '-')
		{
			if (!(sign >= 'A' && sign < 'Z'))
			{
				if (!(sign >= '0' && sign <= '9'))
				{
					throw invalid_argument("Invalid value. Example: 1F ");
				}
			}
			if (sign >= 'A')
			{
				if (sign - AsciiNumDifference >= sourceNotation)
				{
					throw invalid_argument("Each symbol of value must be lower than source notation. Example: 1F in 16 : 1 < 16 and F < 16");
				}
			}
			else if (sign <= '9')
			{
				if (sign - '0' >= sourceNotation)
				{
					throw invalid_argument("Each symbol of value must be lower than source notation. Example: 10 in 2 : 1 < 2 and 0 < 2");
				}
			}
		}
	});
}

long long ToDecimalNotation(const std::string & value, int sourceNotation)
{
	ValidationOfValue(value, sourceNotation);
	if (sourceNotation == 10)
	{
		return stoi(value);
	}
	std::vector<char> digits(value.begin(), value.end());
	long long result = 0;
	bool isNegative = false;
	for (size_t i = 0; i < digits.size(); i++)
	{
		if (digits[i] == '-')
		{
			isNegative = true;
		}
		else if (digits[i] >= 'A')
		{
			result += (digits[i] - AsciiNumDifference) * (long long)pow(sourceNotation, digits.size() - 1 - i);
		}
		else
		{
			result += (digits[i] - '0') * (long long)pow(sourceNotation, digits.size() - 1 - i);
		}
	}
	if (isNegative)
	{
		result *= -1;
	}
	return result;
}

std::string FromDecimalToDestination(long long value, int destNotaion)
{
	bool isNegative = false;
	if (value < 0)
	{
		value *= -1;
		isNegative = true;
	}
	string result;
	while (value >= destNotaion)
	{
		int currRemainder = value % destNotaion;
		if (currRemainder >= 10)
		{
			result += currRemainder + AsciiNumDifference;
		}
		else
		{
			result += to_string(currRemainder);
		}
		value /= destNotaion;
	}
	result += to_string(value);
	if (isNegative)
	{
		result.push_back('-');
	}
	std::reverse(result.begin(), result.end());
	return result;
}

