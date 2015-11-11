// Var4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;

const uintmax_t MAX_SIZE = 2147483648;

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

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 5)
	{
		cout << "Need to input only 4 parameters" << endl;
	}
	else
	{
		string ifile = argv[1];
		string ofile = argv[2];
		string search = argv[3];
		ifstream in;
		ofstream out;
		in.open(ifile);
		if (!in.is_open())
		{
			cout << "Input file does not exist!" << endl;
		}
		else if (file_size(ifile) == 0)
		{
			cout << "Input file is empty!" << endl;
		}
		else if (file_size(ifile) > MAX_SIZE)
		{
			cout << "Size of input file more than 2GB" << endl;
		}
		else if (file_size(ofile) > MAX_SIZE)
		{
			cout << "Size of output file more than 2GB" << endl;
		}
		else
		{
			out.open(ofile);
			string replace = argv[4];
			while (!in.eof())
			{
				string current;
				getline(in, current);
				ReplaceStringInPlace(current, search, replace);
				out.write(current.c_str(), current.length());
				cout << "Done: " + current << endl;
			}
			in.close();
			out.close();
		}
	}

	return 0;
}
