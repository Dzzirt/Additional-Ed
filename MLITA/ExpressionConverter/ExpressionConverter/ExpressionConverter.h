#pragma once

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
	std::string m_expression;
	size_t m_expIndex;
	static std::vector<char> operations;
};

