#pragma once

#include <boost/utility/string_ref.hpp>

class CExpressionConverter
{
public:
	CExpressionConverter() = default;
	std::string ToSuffixNotation(const std::string &expression);
	~CExpressionConverter() = default;
private:
	void HandlePlusAndMinus(std::string & output, size_t & index);
	void HandleMultAndDiv(std::string & output, size_t & index);
	void HandleVariables(std::string & output, size_t & index);

	// TODO: use boost::string_ref m_expression;
	std::string m_expression;
	size_t m_expIndex;

	// TODO: use std::string
	static std::vector<char> operations;
};

