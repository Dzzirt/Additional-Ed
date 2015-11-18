#pragma once

#include <iostream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <vector>

bool is_digits(const std::string &str);

std::vector<std::string> GetVectorOfStrings();

void MultiplyValueByTheMin(std::vector<float> & input);

bool isDigitValues(std::vector<std::string> input);

std::vector<float> StringVecToFloatVec(const std::vector<std::string> & input);

void PrintVector(std::vector<float> float_vec);