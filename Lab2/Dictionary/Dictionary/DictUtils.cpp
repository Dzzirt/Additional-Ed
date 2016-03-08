#include "stdafx.h"
#include "DictUtils.h"
using namespace std;

map<string, string> GetMapFromFile(string filename)
{
	map<string, string> dict;
	string key;
	string val;
	ifstream in(filename);
	while (in >> key >> val)
	{
		dict.insert({ key, val });
	}
	return dict;
}

void AskAndSave(string filename, map<string, string> & newWords)
{
	ofstream out(filename, ios_base::app);
	string save;
	cout << "Сохранить словарь перед выходом? Да / Нет" << endl;
	getline(cin, save);
	if (save == "Да")
	{
		for (auto & pair : newWords)
		{
			out << pair.first << " " << pair.second << endl;
		}
		out.close();
		cout << "Изменения успешно сохранены. До свидания." << endl;
	}
}

bool AddTranslation(string enWord, map<string, string> & dict, map<string, string> & newWords)
{
	string ruWord;
	cout << "Неизвестное слово " << enWord << ". Введите перевод или пустую строку для отказа." << endl;
	getline(cin, ruWord);
	if (!ruWord.empty())
	{
		newWords.insert({ enWord, ruWord });
		dict.insert({ enWord, ruWord });
		cout << "Слово \"" << enWord << "\" сохранено в словаре как \"" << ruWord << "\"." << endl;
		return true;
	}
	else
	{
		cout << "Слово " << enWord << " проигнорировано!" << endl;
	}
	return false;
}

void OpenDictionary(string filename)
{
	cout << "Введите слово на английском языке и я вам его переведу." << endl;
	map<string, string> dict = GetMapFromFile(filename);
	map<string, string> newWords;
	string enWord;
	bool needToSave = false;
	size_t saveFrom = dict.size();
	getline(cin, enWord);
	while (enWord != "...")
	{
		if (dict.find(enWord) == dict.end())
		{
			needToSave = AddTranslation(enWord, dict, newWords);
		}
		else
		{
			cout << dict.at(enWord) << endl;
		}
		getline(cin, enWord);
	}
	if (needToSave)
	{
		AskAndSave(filename, newWords);
	}
}