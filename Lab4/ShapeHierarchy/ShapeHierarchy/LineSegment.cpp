#include "stdafx.h"
#include "LineSegment.h"

CLineSegment::CLineSegment(CPoint first, CPoint second)
	:m_first(first), m_second(second)
{
	m_length = sqrt(pow(second.GetPosition().first - first.GetPosition().first, 2)
	+ pow(second.GetPosition().second - first.GetPosition().second, 2));
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return m_length;
}

std::string CLineSegment::GetBorderColor() const
{
	return m_borderColor;
}

void CLineSegment::SetBorderColor(std::string const& color)
{
	m_borderColor = color;
}

std::string CLineSegment::ToString() const
{
	std::string output = "Line Segment ";
	output += "\n";
	output += "First Point: ";
	output += m_first.ToString();
	output += "\n";
	output += "Second Point: ";
	output += m_second.ToString();
	output += "\n";
	output += "S: " + std::to_string(GetArea());
	output += "\n";
	output += "P: ";
	output += std::to_string(GetPerimeter());
	output += "\n";
	output += "Border Color: ";
	output += GetBorderColor();
	output += "\n";
	output += "=============================";
	return output;
}

