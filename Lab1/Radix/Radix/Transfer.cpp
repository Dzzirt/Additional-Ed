#include "stdafx.h"
#include "Transfer.h"
#include <cmath>
#include <climits>
#include "iostream"
using namespace std;

const int AsciiNumDifference = 55;

template <typename T>
bool IsBetween(const T& value, const T& lowerBound, const T& upperBound)
{
	return !(value < lowerBound) && (value < upperBound);
}

template <typename T>
bool IsWithinRangeInclusive(const T& value, const T& lowerBound, const T& upperBound)
{
	return !(value < lowerBound) || (upperBound < value);
}


int CharToNumber(char character)
{
	if (IsWithinRangeInclusive(character, 'A', 'Z'))
	{
		return static_cast<int>(character - 'A' + 10);
	}
	else if (IsWithinRangeInclusive(character, 'a', 'z'))
	{
		return static_cast<int>(character - 'a' + 10);
	}
	else if (IsWithinRangeInclusive(character, '0', '9'))
	{
		return static_cast<int>(character - '0');
	}
	return character;
}


int AddWithOverflowCheck(int val1, int val2)
{
	if (val2 > 0 && val1 > INT_MAX - val2)
	{
		throw overflow_error("Overflow of Int");
	}
	if (val2 < 0 && val1 < INT_MIN - val2)
	{
		throw underflow_error("Underflow of Int");
	}
	return val1 + val2;
}

int MultiplicationWithOverflowCheck(int val1, int val2, bool isNegative)
{
	if (isNegative)
	{
		val2 *= -1;
	}
	if (val2 > 0 && val1 > INT_MAX / val2)
	{
		throw overflow_error("Overflow of Int");
	}
	if (!(val2 == -1 && val1 != INT_MIN))
	{
		if (val2 < 0 && val1 > INT_MIN / val2)
		{
			throw underflow_error("Underflow of Int");
		}
	}
	if (isNegative)
	{
		val2 *= -1;
	}
	return val1 * val2;
	
}
std::string Transfer(int sourceNotation, int destNotaion, const std::string & value)
{
	if (value == "0")
	{
		return "0";
	}
	auto decimalVal = ToDecimalNotation(value, sourceNotation);
	string result = FromDecimalToDestination(decimalVal, destNotaion);
	return result;
}

void ValidationOfValue(const std::string &value, int sourceNotation)
{
	if (sourceNotation == 10)
	{
		string intMin = to_string(INT_MIN);
		if (value > to_string(INT_MAX))
		{
			throw overflow_error("Overflow of Int");
		}
		if (value[0] == '-')
		{
			if (value > intMin)
			{
				throw underflow_error("Underflow of Int");
			}
		}
	}
	
	for (size_t i = 0; i < value.size(); i++)
	{
		if (value[i] == '-' || value[i] == '+')
		{
			if (i != 0)
			{
				throw invalid_argument("Sign of value must be at first place");
			}
		}
	}
	auto isValid = std::all_of(value.begin(), value.end(), [=](char character) {
		if (character != '-' && character != '+')
		{
			if (!(IsWithinRangeInclusive(character, 'A', 'Z')))
			{
				if (!(IsWithinRangeInclusive(character, '0', '9')))
				{
					if (!(IsWithinRangeInclusive(character, 'a', 'z')))
					{
						return false;
					}
				}
			}
			if (CharToNumber(character) >= sourceNotation)
			{
				return false;
			}
		}
		return true;
	});
	if (!isValid)
	{
		throw invalid_argument("Invalid value. Value can only include chars [0, 9], [A, Z], [a, z]. Also each symbol of value must be lower than source notation");
	}
}

void ValidationOfNotation(int notation)
{
	if (!(IsWithinRangeInclusive(notation, 2, 36)))
	{
		throw invalid_argument("Notation must be in range [2, 36]");
	}
}

int ToDecimalNotation(const std::string & value, int sourceNotation)
{
	ValidationOfValue(value, sourceNotation);
	if (sourceNotation == 10)
	{
		return stoi(value);
	}
	std::vector<char> digits(value.begin(), value.end());
	int result = 0;
	bool isNegative = false;
	int firstNonSignSymbol = 0;
	for (size_t i = 0; i < digits.size(); i++)
	{
		if (digits[i] == '+')
		{
			continue;
		}
		if (digits[i] == '-')
		{
			isNegative = true;
		}
		else
		{
			auto miltiply = MultiplicationWithOverflowCheck(sourceNotation, result, isNegative);
			result = AddWithOverflowCheck(CharToNumber(value[i]), miltiply);
		}
	}
	if (isNegative)
	{
		result *= -1;
	}
	return result;
}

std::string FromDecimalToDestination(int value, int destNotaion)
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
	if (value >= 10)
	{
		result += 'A';
	}
	else
	{
		result += to_string(value);
	}
	
	if (isNegative)
	{
		result.push_back('-');
	}
	return { result.rbegin(), result.rend() };
}

