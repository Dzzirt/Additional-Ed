#pragma once
#include "SolidShape.h"
#include "LineSegment.h"
#include "FillColor.h"

class CTriangle : public IShape, public CBorderColor, public CFillColor
{
public:
	CTriangle() = delete;
	CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3);
	double GetArea()const override;
	double GetPerimeter()const override;
	std::string ToString()const override;
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
};

