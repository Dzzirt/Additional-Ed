#include "stdafx.h"
#include "HtmlEncode.h"

using namespace std;

string HtmlEncode(string const& text)
{
	string result = "";
	for (const auto & character : text)
	{
		if (character == '\'')
		{
			result.append("&apos");
		}
		else if (character == '\"')
		{
			result.append("&quot");
		}
		else if (character == '<')
		{
			result.append("&lt");
		}
		else if (character == '>')
		{
			result.append("&dt");
		}
		else if (character == '&')
		{
			result.append("&amp");
		}
		else
		{
			result += character;
		}
	}
	return result;
}

void ReadInString(std::string & source)
{
	source = { (std::istreambuf_iterator<char>(std::cin)), std::istreambuf_iterator<char>() };
}

void PrintString(std::string &result)
{
	std::copy(result.begin(), result.end(), std::ostreambuf_iterator<char>(std::cout));
}