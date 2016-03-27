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
	std::cout << "����������� ����� " << enWord << ". ������� ������� ��� ������ ������ ��� ������." << endl;
	getline(cin, ruWord);
	return ruWord;
}

void DictionaryUI::PrintSaveMessage(std::string const& ru, std::string const& en)
{
	cout << "����� \"" << en << "\" ��������� � ������� ��� \"" << ru << "\"." << endl;
}

void DictionaryUI::PrintIgnoreMessage(std::string const& ignored)
{
	cout << "����� " << ignored << " ���������������." << endl;
}

void DictionaryUI::PrintTranslateResult(std::string const& result)
{
	cout << result << endl;
}

void DictionaryUI::PrintSaveCompleteMessage()
{
	cout << "��������� ������� ���������. �� ��������." << endl;
}

void DictionaryUI::PrintWelcomeMessage()
{
	cout << "������� ����� �� ���������� ����� � � ��� ��� ��������." << endl;
}

std::string DictionaryUI::AskPermissionForSave()
{
	string save;
	do
	{
		cout << "��������� ������� ����� �������? �� / ���" << endl;
		getline(cin, save);
	} while (save != "��" && save != "���");
	return save;
}
