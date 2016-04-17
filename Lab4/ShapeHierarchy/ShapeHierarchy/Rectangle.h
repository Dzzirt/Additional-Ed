#pragma once
#include "SolidShape.h"
#include "Point.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle() = delete;
	CRectangle(CPoint upperLeft, double width, double height);
	double GetArea()const override;
	double GetPerimeter()const override;
	std::string GetBorderColor()const override;
	void SetBorderColor(std::string const& color) override;
	std::string ToString()const override;
	std::string GetFillColor()const override;
	void SetFillColor(std::string const& color) override;
private:
	CPoint m_upperLeftCorner;
	double m_width;
	double m_height;
	std::string m_borderColor;
	std::string m_fillColor;
};

