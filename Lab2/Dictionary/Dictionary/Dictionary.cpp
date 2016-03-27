#include "stdafx.h"
#include "Dictionary.h"


Dictionary::Dictionary(DictionaryLogic & logic, DictionaryUI & ui)
	:m_logic(logic), m_ui(ui)
{

}


Dictionary::~Dictionary()
{
}

void Dictionary::Exec()
{
	m_ui.PrintWelcomeMessage();
	std::string enWord = m_ui.ReadWordFromConsole();
	while (enWord != "...")
	{
		if (!m_logic.HasWord(enWord))
		{
			AddTranslation(enWord);
		}
		else
		{
			m_ui.PrintTranslateResult(m_logic.GetValueAt(enWord));
		}
		enWord = m_ui.ReadWordFromConsole();
	}
	if (m_logic.GetSaveState())
	{
		string savePerm = m_ui.AskPermissionForSave();
		if (savePerm == "Да")
		{
			m_logic.SaveNewWordsInFile();
			m_ui.PrintSaveCompleteMessage();
		}
	}
}

void Dictionary::AddsTranslationIfNotEmpty(std::string const& userInput, std::string const& enWord)
{
	if (!userInput.empty())
	{
		m_ui.PrintSaveMessage(enWord, userInput);
		m_logic.InsertPair(enWord, userInput);
		m_logic.SetSaveState(true);
	}
}
void Dictionary::AddTranslation(string const& enWord)
{
	std::string userInput = m_ui.AskUserForInputTranslationOrRefuse(enWord);
	AddsTranslationIfNotEmpty(userInput, enWord);
	if (userInput.empty())
	{
		m_ui.PrintIgnoreMessage(enWord);
	}
}

