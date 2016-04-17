#include "stdafx.h"
#include "Triangle.h"


CTriangle::CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3)
	:m_vertex1(vertex1), m_vertex2(vertex2), m_vertex3(vertex3)
{
	
}

double CTriangle::GetArea() const
{
	auto baseLen = GetBaseLine().GetPerimeter();
	auto leftLen = GetLeftEdge().GetPerimeter();
	auto rightLen = GetRightEdge().GetPerimeter();
	auto p = (baseLen + leftLen + rightLen) / 2.f;
	return sqrt(p * (p - baseLen) * (p - leftLen) * (p - rightLen));
}

double CTriangle::GetPerimeter() const
{
	auto baseLen = GetBaseLine().GetPerimeter();
	auto leftLen = GetLeftEdge().GetPerimeter();
	auto rightLen = GetRightEdge().GetPerimeter();
	return baseLen + leftLen + rightLen;
}

std::string CTriangle::GetBorderColor() const
{
	return m_borderColor;
}

void CTriangle::SetBorderColor(std::string const& color)
{
	m_borderColor = color;
}

std::string CTriangle::ToString() const
{
	std::string output = "Triangle ";
	output += "\n";
	output += "Vertexes: ";
	output += "\n";
	output += m_vertex1.ToString();
	output += "\n";
	output += m_vertex2.ToString();
	output += "\n";
	output += m_vertex3.ToString();
	output += "\n";
	output += "S: " + std::to_string(GetArea());
	output += "\n";
	output += "P: ";
	output += std::to_string(GetPerimeter());
	output += "\n";
	output += "Border Color: ";
	output += GetBorderColor();
	output += "\n";
	output += "Fill Color: ";
	output += GetFillColor();
	output += "\n";
	output += "=============================";
	return output;
}

std::string CTriangle::GetFillColor() const
{
	return m_fillColor;
}

void CTriangle::SetFillColor(std::string const& color)
{
	m_fillColor = color;
}

CLineSegment CTriangle::GetBaseLine() const
{
	return CLineSegment(m_vertex1, m_vertex3);
}

CLineSegment CTriangle::GetLeftEdge() const
{
	return CLineSegment(m_vertex1, m_vertex2);
}

CLineSegment CTriangle::GetRightEdge() const
{
	return CLineSegment(m_vertex2, m_vertex3);
}

