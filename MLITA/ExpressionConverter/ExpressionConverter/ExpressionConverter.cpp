#include "stdafx.h"
#include "ExpressionConverter.h"

using namespace std;
using namespace boost::algorithm;

// ParseExprSum
void CExpressionConverter::HandlePlusAndMinus(std::string & output)
{
	HandleMultAndDiv(output);
	while (m_expression.starts_with("+") || m_expression.starts_with("-")) {
		char temp = m_expression.front();
		m_expression.remove_prefix(1);
		HandleMultAndDiv(output);
		output += temp;
		output += " ";
	}
}

// ParseExprMul
void CExpressionConverter::HandleMultAndDiv(std::string & output)
{
	HandleVariables(output);
	while (m_expression.starts_with("*") || m_expression.starts_with("/")) {
		char temp = m_expression.front();
		m_expression.remove_prefix(1);
		HandleVariables(output);
		output += temp;
		output += " ";
	}
}

// ParseAtom
void CExpressionConverter::HandleVariables(std::string & output)
{
	if (m_expression.starts_with("(")) {
		m_expression.remove_prefix(1);
		HandlePlusAndMinus(output);
		if (!m_expression.starts_with(")")) {
			throw std::invalid_argument("Error: wrong number of brackets");
		}
		else
		{
			m_expression.remove_prefix(1);
		};
	}
	else 
	{
		while (any_of("0123456789.,", bind2nd(std::equal_to<char>(), m_expression.front()))
			&& m_expression.length() != 0)
		{
			output += m_expression.front();
			m_expression.remove_prefix(1);
		}
		output += " ";
	}	
}

std::string CExpressionConverter::ToSuffixNotation(boost::string_ref expression)
{
	auto str = expression.to_string();
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	m_expression = str;
	string output;
	HandlePlusAndMinus(output);
	if (!output.empty())
	{
		output.erase(--output.end());
	}
	return output;
}