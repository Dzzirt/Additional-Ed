#pragma once

#include <iostream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <vector>


bool IsDigits(const std::string &str);

std::vector<std::string> GetVectorOfStrings();

void MultiplyValueByTheMin(std::vector<float> & input);

bool IsDigitValues(const std::vector<std::string>& input);

std::vector<float> StringVecToFloatVec(const std::vector<std::string> & input);

void PrintVector(const std::vector<float>& float_vec);

void SortVector(std::vector<float> & float_vec);