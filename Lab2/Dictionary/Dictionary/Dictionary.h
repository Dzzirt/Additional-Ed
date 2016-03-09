#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>

class Dictionary
{
public:
	Dictionary(std::string const& filename);
	~Dictionary();
	void InteractWithUser();
private:
	std::map<std::string, std::string> newWords;
	std::map<std::string, std::string> oldWords;
	std::string filename;

	std::map<std::string, std::string> GetMapFromFile(std::string const& filename);
	void SaveDictionaryIfUserAgrees();
	bool AddTranslation(std::string const& enWord);
};



