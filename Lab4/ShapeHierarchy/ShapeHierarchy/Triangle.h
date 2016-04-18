#pragma once
#include "SolidShape.h"
#include "LineSegment.h"

class CTriangle : public ISolidShape
{
public:
	CTriangle() = delete;
	CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3);
	double GetArea()const override;
	double GetPerimeter()const override;
	CColorRGB GetBorderColor()const override;
	void SetBorderColor(CColorRGB const& color) override;
	std::string ToString()const override;
	CColorRGB GetFillColor()const override;
	void SetFillColor(CColorRGB const& color) override;
	CLineSegment GetBaseLine()const;
	CLineSegment GetLeftEdge()const;
	CLineSegment GetRightEdge()const;
	CPoint GetMiddleVertex()const;
	CPoint GetLeftVertex()const;
	CPoint GetRightVertex()const;
	Shapes GetType()const override;
private:
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
	CColorRGB m_borderColor;
	CColorRGB m_fillColor;
};

