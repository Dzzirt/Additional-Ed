#include "stdafx.h"
#include "Rectangle.h"
#include <cassert>



CRectangle::CRectangle(CPoint upperLeft, double width, double height)
	: m_upperLeftCorner(upperLeft), m_width(width), m_height(height)
{
	if (width < 0 || height < 0)
	{
		throw std::invalid_argument("Width and height should have positive values");
	};
}

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return (m_width + m_height) * 2;
}

std::string CRectangle::GetBorderColor() const
{
	return m_borderColor;
}

void CRectangle::SetBorderColor(std::string const& color)
{
	m_borderColor = color;
}

std::string CRectangle::ToString() const
{
	std::string output = "Rectangle ";
	output += "\n";
	output += "pos: ";
	output += m_upperLeftCorner.ToString();
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

std::string CRectangle::GetFillColor() const
{
	return m_fillColor;
}

void CRectangle::SetFillColor(std::string const& color)
{
	m_fillColor = color;
}

