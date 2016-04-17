#pragma once
#include "Shape.h"
#include "Point.h"

class CLineSegment :public IShape
{
public:
	CLineSegment() = delete;
	CLineSegment(CPoint first, CPoint second);
	double GetArea()const override;
	double GetPerimeter()const override;
	std::string GetBorderColor()const override;
	void SetBorderColor(std::string const& color) override;
	std::string ToString()const override;

private:
	CPoint m_first;
	CPoint m_second;
	double m_length;
	std::string m_borderColor;
};

