#include "stdafx.h"
#include "DictionaryUI.h"
#include <iostream>
#include <string>
using namespace std;

DictionaryUI::DictionaryUI()
{
	
}


DictionaryUI::~DictionaryUI()
{
}

std::string DictionaryUI::ReadWordFromConsole()
{
	string enWord;
	getline(cin, enWord);
	return enWord;
}

std::string DictionaryUI::AskUserForInputTranslationOrRefuse(std::string const& enWord)
{
	string ruWord;
	std::cout << "Неизвестное слово " << enWord << ". Введите перевод или пустую строку для отказа." << endl;
	getline(cin, ruWord);
	return ruWord;
}

void DictionaryUI::PrintSaveMessage(std::string const& ru, std::string const& en)
{
	cout << "Слово \"" << en << "\" сохранено в словаре как \"" << ru << "\"." << endl;
}

void DictionaryUI::PrintIgnoreMessage(std::string const& ignored)
{
	cout << "Слово " << ignored << " проигнорировано." << endl;
}

void DictionaryUI::PrintTranslateResult(std::string const& result)
{
	cout << result << endl;
}

void DictionaryUI::PrintSaveCompleteMessage()
{
	cout << "Изменения успешно сохранены. До свидания." << endl;
}

void DictionaryUI::PrintWelcomeMessage()
{
	cout << "Введите слово на английском языке и я вам его переведу." << endl;
}

std::string DictionaryUI::AskPermissionForSave()
{
	string save;
	do
	{
		cout << "Сохранить словарь перед выходом? Да / Нет" << endl;
		getline(cin, save);
	} while (save != "Да" && save != "Нет");
	return save;
}
