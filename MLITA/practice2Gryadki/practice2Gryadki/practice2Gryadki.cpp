// practice2Gryadki.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "fstream"
#include "iostream"
#include "string"
#include "vector"
#include "boost/algorithm/string.hpp"
#include "stack"
using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Usage: <input file>" << endl;
	}
	string fileName = argv[1];
	ifstream in(fileName);
	string fieldInfo;
	getline(in, fieldInfo);
	std::vector<string> info;
	boost::split(info, fieldInfo, boost::is_any_of(" "));
	size_t row = stoi(info[0]);
	size_t col = stoi(info[1]);
	string currLine;
	vector<shared_ptr<vector<char>>> grove;
	for (size_t i = 0; i < row; i++)
	{
		if (getline(in, currLine))
		{
			grove.push_back(make_shared<vector<char>>());
		}
		else
		{
			break;
		}
		for (size_t j = 0; j < col; j++)
		{
			grove[i]->push_back(currLine[j]);
		}
	}

	std::vector<std::shared_ptr<std::vector<bool>>> marked;
	for (size_t i = 0; i < row; i++)
	{
		marked.push_back(make_shared<std::vector<bool>>());
		for (size_t j = 0; j < col; j++)
		{
			marked[i]->push_back(false);
		}
	}
	int fieldCount = 0;
	pair<int, int> prevPos = { 0, 0 };
	std::stack<pair<int, int>> prevPoses;
	prevPoses.push(prevPos);
	for (size_t i = 0; i < grove.size(); i++)
	{
		for (size_t j = 0; j < grove[0]->size(); j++)
		{
			bool stillSearch = true;
			while (stillSearch && grove[i]->at(j) != '.')
			{
				if (grove[i]->at(j) == '#')
				{
					marked[i]->at(j) = true;
					if (j != grove[0]->size() - 1 && grove[i]->at(j + 1) == '#' && !marked[i]->at(j + 1))
					{
						prevPoses.push({ i, j });
						j++;
					}
					else if (j != 0 && grove[i]->at(j - 1) == '#' && !marked[i]->at(j - 1))
					{
						prevPoses.push({ i, j });
						j--;
					}
					else if (i != grove.size() - 1 && grove[i + 1]->at(j) == '#' && !marked[i + 1]->at(j))
					{
						prevPoses.push({ i, j });
						i++;
					}
					else if (i != 0 && grove[i - 1]->at(j) == '#' && !marked[i - 1]->at(j))
					{
						prevPoses.push({ i, j });
						i--;
					}
					else
					{
						grove[i]->at(j) = '.';
						if (prevPoses.size() != 1)
						{
							auto pair = prevPoses.top();
							prevPoses.pop();
							i = pair.first;
							j = pair.second;
						}
						else
						{
							stillSearch = false;
							fieldCount++;
						}
					}
				}
			}
			
		}
	}
	cout << fieldCount << endl;
	return 0;
}

