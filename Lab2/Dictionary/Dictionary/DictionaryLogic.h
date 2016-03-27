#pragma once
#include <string>
#include <map>

class DictionaryLogic
{
public:
	DictionaryLogic(std::string const& filename);
	~DictionaryLogic();
	bool HasWord(std::string const& word);
	std::string GetValueAt(std::string const& word);
	void InsertPair(std::string const& first, std::string const& second);
	void SetSaveState(bool flag);
	bool GetSaveState();
	void SaveNewWordsInFile();
	std::map<std::string, std::string> DictionaryLogic::GetMapFromFile();
private:
	std::string m_filename;
	std::map<std::string, std::string> m_newWords;
	std::map<std::string, std::string> m_oldWords;
	bool m_needToSave;

};

