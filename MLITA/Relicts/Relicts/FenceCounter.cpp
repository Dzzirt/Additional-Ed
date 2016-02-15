#include "FenceCounter.h"

using namespace std;

vector<shared_ptr<vector<char>>> FillFromFile(string fileName)
{
	ifstream in(fileName);
	string fieldInfo;
	getline(in, fieldInfo);
	vector<string> parsedInfo;
	boost::split(parsedInfo, fieldInfo, boost::is_any_of(" "));
	size_t row = stoi(parsedInfo[0]);
	size_t col = stoi(parsedInfo[1]);
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
	return grove;
}

unsigned int CountFences(std::vector<shared_ptr<vector<char>>> const& grove)
{
	unsigned int fencesCount = 0;
	for (size_t row = 0; row < grove.size(); row++)
	{
		for (size_t col = 0; col < grove[0]->size(); col++)
		{
			if (grove[row]->at(col) == '1')
			{
				if (row == 0)
				{
					fencesCount++;
				}
				else if (!(grove[row - 1]->at(col) == '1'))
				{
					fencesCount++;
				}
				if (row == grove.size() - 1)
				{
					fencesCount++;
				}
				else if (!(grove[row + 1]->at(col) == '1'))
				{
					fencesCount++;
				}
				if (col == 0)
				{
					fencesCount++;
				}
				else if (!(grove[row]->at(col - 1) == '1'))
				{
					fencesCount++;
				}
				if (col == grove[0]->size() - 1)
				{
					fencesCount++;
				}
				else if (!(grove[row]->at(col + 1) == '1'))
				{
					fencesCount++;
				}
			}
		}
	}
	return fencesCount;
}
