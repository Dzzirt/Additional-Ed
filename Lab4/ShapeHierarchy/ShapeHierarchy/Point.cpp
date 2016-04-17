#include "stdafx.h"
#include "Point.h"

CPoint::CPoint(double x, double y)
	:m_pos(std::make_pair(x, y))
{

}

std::pair<double, double> CPoint::GetPosition() const
{
	return m_pos;
}

void CPoint::SetPosition(double x, double y)
{
	m_pos.first = x;
	m_pos.second = y;
}

double CPoint::GetArea()const
{
	return 0;
}

double CPoint::GetPerimeter()const
{
	return 0;
}

std::string CPoint::GetBorderColor()const
{
	return "";
}

void CPoint::SetBorderColor(std::string const& color)
{

}

std::string CPoint::ToString()const
{
	std::string output = "(";
	output += std::to_string(GetPosition().first);
	output += ";";
	output += std::to_string(GetPosition().second);
	output += ")";
	return output;
}