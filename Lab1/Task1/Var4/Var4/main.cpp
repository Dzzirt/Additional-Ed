// Var4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;

const uintmax_t MAX_SIZE = 2147483648UL;

// replace.exe <input file> <output file> <search string> <replace string>

void ReplaceStringInPlace(string& subject, const string& search, const string& replace)
{
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != string::npos)
	{
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
}

void ReplaceStringInFile(string inputFileName, string outputFileName, string search, string replace)
{
	ifstream in;
	ofstream out;
	in.open(inputFileName);
	if (!in.is_open()) {
		cout << "Input file does not exist!" << endl;
	}
	else if (file_size(inputFileName) == 0) {
		cout << "Input file is empty!" << endl;
	}
	else if (file_size(inputFileName) > MAX_SIZE) {
		cout << "Size of input file more than 2GB" << endl;
	}
	else if (file_size(outputFileName) > MAX_SIZE) {
		cout << "Size of output file more than 2GB" << endl;
	}
	else {
		out.open(outputFileName);
		while (!in.eof()) {
			string current;
			getline(in, current);
			ReplaceStringInPlace(current, search, replace);
			out.write(current.c_str(), current.length());
			cout << "Done: " + current << endl;
		}
		out.close();
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 5)
	{
		cout << "Usage:\nreplace.exe <input - file> <output - file> <search - string> <replace - string>\n" << endl;
	}
	else
	{
		ReplaceStringInFile(argv[1], argv[2], argv[3], argv[4]);
	}

	return 0;
}
