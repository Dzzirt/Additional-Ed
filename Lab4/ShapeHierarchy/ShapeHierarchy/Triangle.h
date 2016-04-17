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
	std::string GetBorderColor()const override;
	void SetBorderColor(std::string const& color) override;
	std::string ToString()const override;
	std::string GetFillColor()const override;
	void SetFillColor(std::string const& color) override;
	CLineSegment GetBaseLine()const;
	CLineSegment GetLeftEdge()const;
	CLineSegment GetRightEdge()const;
private:
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
	std::string m_borderColor;
	std::string m_fillColor;
};

