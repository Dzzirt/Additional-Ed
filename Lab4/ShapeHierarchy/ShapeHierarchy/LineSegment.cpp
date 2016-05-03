#include "stdafx.h"
#include "LineSegment.h"
#include "Visitor.h"

CLineSegment::CLineSegment(CPoint first, CPoint second)
	:m_first(first), m_second(second)
{
	m_length = sqrt(pow(second.GetPosition().x - first.GetPosition().x, 2)
	+ pow(second.GetPosition().y - first.GetPosition().y, 2));
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return m_length;
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

CPoint CLineSegment::GetFirstPoint() const
{
	return m_first;
}

CPoint CLineSegment::GetSecondPoint() const
{
	return m_second;
}

void CLineSegment::Accept(IVisitor & visitor)
{
	visitor.Visit(*this);
}

/*
bool CLineSegment::operator==(CLineSegment const& other)
{
	return (m_first == other.GetFirstPoint())
		&& (m_second == other.GetSecondPoint())
		&& (m_length == other.GetPerimeter());
}*/

bool operator==(CLineSegment const& lhs, CLineSegment const& rhs)
{
	return (lhs.GetFirstPoint() == rhs.GetFirstPoint())
		&& (lhs.GetSecondPoint() == rhs.GetSecondPoint())
		&& (lhs.GetPerimeter() == rhs.GetPerimeter());
}
