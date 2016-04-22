#include "stdafx.h"
#include "Point.h"

CPoint::CPoint(double x, double y)
	:m_pos(Vector2Double(x, y))
{

}

Vector2Double CPoint::GetPosition() const
{
	return m_pos;
}

void CPoint::SetPosition(double x, double y)
{
	m_pos.x = x;
	m_pos.y = y;
}

double CPoint::GetArea()const
{
	return 0;
}

double CPoint::GetPerimeter()const
{
	return 0;
}

std::string CPoint::ToString()const
{
	std::string output = "(";
	output += std::to_string(GetPosition().x);
	output += ";";
	output += std::to_string(GetPosition().y);
	output += ")";
	return output;
}

void CPoint::Accept(IVisitor & visitor)
{

}
