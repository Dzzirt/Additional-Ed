#include <fstream>
#include <string>
#include <vector>
#include "boost/algorithm/string.hpp"

std::vector<std::shared_ptr<std::vector<char>>> FillFromFile(std::string fileName);

unsigned int CountFences(std::vector<std::shared_ptr<std::vector<char>>> const& grove);