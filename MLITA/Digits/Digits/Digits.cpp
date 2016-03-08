// Digits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	ifstream in("input.txt");
	std::vector<std::pair<long long, long long>> vec;
	long long val;
	while (in)
	{
		in >> val;
		auto & it = std::find(vec.begin(), vec.end(), val);
		if (it != vec.end())
		{
			auto & val = *it;
			val.second++;
		}
		else
		{
			vec.push_back({ val, 0 });
		}
	}
	
	return 0;
}

