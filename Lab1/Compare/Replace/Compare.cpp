#include "Compare.h"
#include "fstream"

using namespace std;

size_t compare(const std::string & firstFileName, const std::string & secondFileName)
{
	ifstream first(firstFileName);
	ifstream second(secondFileName);
	size_t currentPos = 0;
	string lineOfFirst;
	string lineOfSecond;
	while (!first.eof() && !second.eof())
	{
		currentPos++;
		getline(first, lineOfFirst);
		getline(second, lineOfSecond);
		if (lineOfFirst != lineOfSecond)
		{
			return currentPos;
		}
	}
	if ((first.eof() && !second.eof()) || (!first.eof() && second.eof()))
	{
		return currentPos;
	}
	return string::npos;
}

