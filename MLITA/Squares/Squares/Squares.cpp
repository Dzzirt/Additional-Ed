// Squares.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include "string"
#include "vector"
#include <algorithm>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	string sourceStr;
	getline(in, sourceStr);
	int source = stoi(sourceStr);
	vector<vector<int>> absolute;
	//25
	for (size_t i = source; i > 0 ; i--)
	{
		int square = i * i;
		if (square == source)
		{
			out << 1 << endl;
			out << i;
			out.close();
			return 1;
		}
		if (square < source)
		{
			vector<int> possible;
			possible.push_back(i * i);
			int capacitor = 0;
			for (size_t j = i; j > 0; j--)
			{
				capacitor += j * j + square;
				if (capacitor == source)
				{
					possible.push_back(j * j);
					absolute.push_back(possible);
					break;
				}
				if (capacitor < source)
				{
					capacitor -= square;
					possible.push_back(j * j);

					j++;
				}
				else
				{
					capacitor -= j * j + square;
				}
			}
		}
	}
	std::sort(absolute.begin(), absolute.end(), [](const std::vector< int >& a, const std::vector< int >& b)
	{
		return a.size() < b.size();
	});
	out << absolute[0].size() << endl;
	std::copy(absolute[0].begin(), absolute[0].end(), std::ostream_iterator<double>(out, " "));
	out.close();
	return 0;
}

