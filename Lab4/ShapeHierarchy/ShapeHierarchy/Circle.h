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
	std::string GetBorderColor()const override;
	void SetBorderColor(std::string const& color) override;
	std::string ToString()const override;
	std::string GetFillColor()const override;
	void SetFillColor(std::string const& color) override;
	double GetRadius()const;
	CPoint GetCenter()const;
private:
	CPoint m_center;
	double m_radius;
	std::string m_borderColor;
	std::string m_fillColor;
};

