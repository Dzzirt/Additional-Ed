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
	CColorRGB GetBorderColor()const;
	double GetWidth()const;
	double GetHeight()const;
	std::pair<double, double> GetPosition()const;
	void SetBorderColor(CColorRGB const& color);
	std::string ToString()const override;
	CColorRGB GetFillColor()const override;
	void SetFillColor(CColorRGB const& color) override;
	Shapes GetType()const override;

private:
	CPoint m_upperLeftCorner;
	double m_width;
	double m_height;
	CColorRGB m_borderColor;
	CColorRGB m_fillColor;
};

