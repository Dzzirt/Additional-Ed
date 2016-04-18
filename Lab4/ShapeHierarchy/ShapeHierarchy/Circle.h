#pragma once
#include "SolidShape.h"
#include "Point.h"

class CCircle : public ISolidShape
{
public:
	CCircle() = delete;
	CCircle(CPoint center, double radius);
	double GetArea()const override;
	double GetPerimeter()const override;
	CColorRGB GetBorderColor()const override;
	void SetBorderColor(CColorRGB const& color) override;
	std::string ToString()const override;
	CColorRGB GetFillColor()const override;
	void CCircle::SetFillColor(CColorRGB const& color);
	double GetRadius()const;
	CPoint GetCenter()const;
	Shapes GetType()const override;
private:
	CPoint m_center;
	double m_radius;
	CColorRGB m_borderColor;
	CColorRGB m_fillColor;
};

