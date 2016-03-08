#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>


void OpenDictionary(std::string filename);
std::map<std::string, std::string> GetMapFromFile(std::string filename);
void AskAndSave(std::string filename, std::map<std::string, std::string> & newWords);
bool AddTranslation(std::string enWord, std::map<std::string, std::string> & dict, std::map<std::string, std::string> & newWords);
