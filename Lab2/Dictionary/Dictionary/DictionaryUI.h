#pragma once
#include <iostream>
using namespace std;

class DictionaryUI
{
public:
	DictionaryUI();
	~DictionaryUI();
	std::string ReadWordFromConsole();
	std::string AskUserForInputTranslationOrRefuse(std::string const& enWord);
	std::string AskPermissionForSave();
	void PrintSaveMessage(std::string const& ru, std::string const& en);
	void PrintIgnoreMessage(std::string const& ignored);
	void PrintTranslateResult(std::string const& result);
	void PrintSaveCompleteMessage();
	void PrintWelcomeMessage();

};

