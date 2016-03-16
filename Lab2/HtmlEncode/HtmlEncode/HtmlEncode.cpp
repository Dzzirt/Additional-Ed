#include "stdafx.h"
#include "HtmlEncode.h"

using namespace std;

string HtmlEncode(string const& text)
{
	string result;
	result.reserve(text.length());
	for (const auto & character : text)
	{
		switch (character)
		{
		case '\'':
			result.append("&apos;");
			break;
		case '\"':
			result.append("&quot;");
			break;
		case '<':
			result.append("&lt;");
			break;
		case '>':
			result.append("&dt;");
			break;
		case '&':
			result.append("&amp;");
			break;
		default:
			result += character;
			break;
		}
	}
	return result;
}

std::string ReadIntoString()
{
	string line;
	getline(std::cin, line);
	return line;
}

void PrintString(std::string &result)
{
	std::copy(result.begin(), result.end(), std::ostreambuf_iterator<char>(std::cout));
}