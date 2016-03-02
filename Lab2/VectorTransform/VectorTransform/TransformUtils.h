#pragma once
#include "vector"
#include "iostream"
#include <iterator>
#include <algorithm>  
#include <boost/phoenix.hpp>
#include <boost/range/algorithm/transform.hpp>

std::vector<double> ReadInVector();

void DevideEachOn(std::vector<double> & numbers, double value);

void Sort(std::vector<double> & numbers);

void PrintSeparatedByComma(std::vector<double> const& numbers);

std::vector<double> Transform(std::vector<double> const&numbers);