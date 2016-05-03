#include "stdafx.h"
#include "Rectangle.h"
#include <cassert>
#include "Visitor.h"


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

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}

Vector2Double CRectangle::GetPosition() const
{
	return m_upperLeftCorner.GetPosition();
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
	output += std::to_string(GetBorderColor().r);
	output += " ";
	output += std::to_string(GetBorderColor().g);
	output += " ";
	output += std::to_string(GetBorderColor().b);
	output += "\n";
	output += "Fill Color: ";
	output += std::to_string(GetFillColor().r);
	output += " ";
	output += std::to_string(GetFillColor().g);
	output += " ";
	output += std::to_string(GetFillColor().b);
	output += "\n";
	output += "=============================";
	return output;
}

void CRectangle::Accept(IVisitor & visitor)
{
	visitor.Visit(*this);
}

