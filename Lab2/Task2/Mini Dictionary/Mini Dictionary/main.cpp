// Mini Dictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "sstream"
#include <map>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	cout << "Привет, я ваш мини-словарь." << endl;
	cout << "Введите слово на англ. языке: " << endl;
	fstream dict_file(argv[1]);
	map<string, string> dict;
	while (!dict_file.eof()) {
		string curr_word;
		getline(dict_file, curr_word);
		vector<string> splited_words;
		boost::split(splited_words, curr_word, boost::is_any_of(" "));
	}
	string input_word;
	cin >> input_word;

	return 0;
}
