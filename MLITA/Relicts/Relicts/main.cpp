#include "stdafx.h"
#include <iostream>
#include "FenceCounter.h"
#include "fstream"
using namespace std;


int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Usage: relicts.exe <input file> <output file>" << endl;
		return 1;
	}
	string infileName = argv[1];
	string outfileName = argv[2];
	auto grove = FillFromFile(infileName);
	ofstream out(outfileName);
	out << CountFences(grove);
	out.close();
	return 0;
}

