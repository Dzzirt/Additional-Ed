#include "stdafx.h"
#include <vector>
#include "Dictionary.h"
#include "boost/algorithm/string.hpp"
using namespace std;


Dictionary::Dictionary(string const& filename)
{
	this->filename = filename;
	oldWords = GetMapFromFile(filename);

}

Dictionary::~Dictionary()
{

}

map<string, string> Dictionary::GetMapFromFile(string const& filename)
{
	map<string, string> dict;
	string pair;
	ifstream in(filename);
	while (getline(in, pair))
	{
		vector<string> splittedPair;
		boost::split(splittedPair, pair, boost::is_any_of(":"));
		dict.emplace(move(splittedPair[0]), move(splittedPair[1]));
	}
	return dict;
}

void Dictionary::SaveDictionaryIfUserAgrees()
{
	ofstream out(filename, ios_base::app);
	string save;
	cout << "Сохранить словарь перед выходом? Да / Нет" << endl;
	getline(cin, save);
	if (save == "Да")
	{
		for (auto & pair : newWords)
		{
			out << pair.first << ":" << pair.second << endl;
		}
		out.close();
		cout << "Изменения успешно сохранены. До свидания." << endl;
	}
}

bool Dictionary::AddTranslation(string const& enWord)
{
	string ruWord;
	cout << "Неизвестное слово " << enWord << ". Введите перевод или пустую строку для отказа." << endl;
	getline(cin, ruWord);
	if (!ruWord.empty())
	{
		cout << "Слово \"" << enWord << "\" сохранено в словаре как \"" << ruWord << "\"." << endl;
		newWords.emplace(enWord, ruWord);
		oldWords.emplace(move(enWord), move(ruWord));
		return true;
	}
	else
	{
		cout << "Слово " << enWord << " проигнорировано!" << endl;
	}
	return false;
}

void Dictionary::InteractWithUser()
{
	cout << "Введите слово на английском языке и я вам его переведу." << endl;
	string enWord;
	bool needToSave = false;
	size_t saveFrom = oldWords.size();
	getline(cin, enWord);
	while (enWord != "...")
	{
		if (oldWords.find(enWord) == oldWords.end())
		{
			needToSave = AddTranslation(enWord);
		}
		else
		{
			cout << oldWords.at(enWord) << endl;
		}
		getline(cin, enWord);
	}
	if (needToSave)
	{
		SaveDictionaryIfUserAgrees();
	}
}