#include "stdafx.h"
#include "Circle.h"
#define _USE_MATH_DEFINES
#include <math.h>


CCircle::CCircle(CPoint center, double radius)
	:m_center(center), m_radius(radius)
{
}

double CCircle::GetArea() const
{
	return M_PI * GetRadius() * GetRadius();
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * GetRadius();
}

std::string CCircle::GetBorderColor() const
{
	return m_borderColor;
}

void CCircle::SetBorderColor(std::string const& color)
{
	m_borderColor = color;
}

std::string CCircle::ToString() const
{
	std::string output = "Circle\n";
	output += "Center: ";
	output += GetCenter().ToString();
	output += "\n";
	output += "R:";
	output += std::to_string(GetRadius());
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

std::string CCircle::GetFillColor() const
{
	return m_fillColor;
}

void CCircle::SetFillColor(std::string const& color)
{
	m_fillColor = color;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}
