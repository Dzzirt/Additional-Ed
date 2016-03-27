#pragma once
#include "DictionaryLogic.h"
#include "DictionaryUI.h"

class Dictionary
{
public:
	Dictionary(DictionaryLogic & logic, DictionaryUI & ui);
	~Dictionary();
	void Exec();
private:
	DictionaryLogic & m_logic;
	DictionaryUI & m_ui;

	void AddTranslation(std::string const& enWord);
	void AddsTranslationIfNotEmpty(std::string const& userInput, std::string const& enWord);
};

