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

CColorRGB CLineSegment::GetBorderColor() const 
{
	return m_borderColor;
}

void CLineSegment::SetBorderColor(CColorRGB const& color)
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
	output += std::to_string(GetBorderColor().r);
	output += " ";
	output += std::to_string(GetBorderColor().g);
	output += " ";
	output += std::to_string(GetBorderColor().b);
	output += "\n";
	output += "=============================";
	return output;
}

Shapes CLineSegment::GetType() const
{
	return LINE_SEGMENT;
}

CPoint CLineSegment::GetFirstPoint() const
{
	return m_first;
}

CPoint CLineSegment::GetSecondPoint() const
{
	return m_second;
}

