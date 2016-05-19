#pragma once

class CExpressionConverter
{
public:
	CExpressionConverter() = default;
	std::string ToSuffixNotation(boost::string_ref expression);
	~CExpressionConverter() = default;
private:
	void HandlePlusAndMinus(std::string & output);
	void HandleMultAndDiv(std::string & output);
	void HandleVariables(std::string & output);
	boost::string_ref m_expression;
};

