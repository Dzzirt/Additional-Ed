#include "stdafx.h"
#include "DictionaryLogic.h"
#include "boost/algorithm/string.hpp"
#include <fstream>
#include <vector>
using namespace std;

DictionaryLogic::DictionaryLogic(std::string const& filename)
	: m_filename(filename), m_oldWords(GetMapFromFile())
{
}


DictionaryLogic::~DictionaryLogic()
{
}

bool DictionaryLogic::HasWord(std::string const& word)
{
	return m_oldWords.find(word) != m_oldWords.end();
}

std::string DictionaryLogic::GetValueAt(std::string const& word)
{
	std::string result;
	try
	{
		result = m_oldWords.at(word);
	}
	catch (std::out_of_range const & e)
	{
		std::ignore = e;
	}
	return result;
}

void DictionaryLogic::InsertPair(std::string const& first, std::string const& second)
{
	m_newWords.emplace(first, second);
	m_oldWords.emplace(first, second);
}

void DictionaryLogic::SetSaveState(bool flag)
{
	m_needToSave = flag;
}

bool DictionaryLogic::GetSaveState()
{
	return m_needToSave;
}

void DictionaryLogic::SaveNewWordsInFile()
{
	ofstream out(m_filename, ios_base::app);
	for (auto & pair : m_newWords)
	{
		out << pair.first << ":" << pair.second << endl;
	}
	out.close();
}

map<string, string> DictionaryLogic::GetMapFromFile()
{
	map<string, string> dict;
	string pair;
	ifstream in(m_filename);
	while (getline(in, pair))
	{
		vector<string> splittedPair;
		boost::split(splittedPair, pair, bind2nd(equal_to<char>(), ':'));
		dict.emplace(move(splittedPair[0]), move(splittedPair[1]));
	}
	return dict;
}
