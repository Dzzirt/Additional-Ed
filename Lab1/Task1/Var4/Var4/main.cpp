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
		string before_the_word = subject.substr(0, pos);
		string after_the_word = subject.substr(pos + search.length(), subject.length() - (pos - search.length()));
		subject = before_the_word + replace + after_the_word;
		pos = pos + search.length();
	}
}


int ReplaceStringInFile(const string& inputFileName, const string& outputFileName, const string& search, const string& replace)
{
	ifstream in;
	ofstream out;
	in.open(inputFileName);
	if (!in.is_open())
	{
		cout << "Input file does not exist!" << endl;
		return -1;
	}
	if (file_size(inputFileName) == 0)
	{
		cout << "Input file is empty!" << endl;
		return 0;
	}
	out.open(outputFileName);
	while (!in.eof())
	{
		string current;
		getline(in, current);
		ReplaceStringInPlace(current, search, replace);
		out.write(current.c_str(), current.length());
	}
	out.close();
	return 0;
}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 5)
	{
		cout << "Usage:\nreplace.exe <input - file> <output - file> <search - string> <replace - string>\n" << endl;
		return -1;
	}
	{
		ReplaceStringInFile(argv[1], argv[2], argv[3], argv[4]);
	}

	return 0;
}
