#pragma once
#include "Shape.h"
#include "Point.h"
#include "BorderColor.h"

class CLineSegment :public IShape, public CBorderColor
{
public:
	CLineSegment() = delete;
	CLineSegment(CPoint first, CPoint second);
	double GetArea()const override;
	double GetPerimeter()const override;
	std::string ToString()const override;
	Shapes GetType()const override;
	CPoint GetFirstPoint()const;
	CPoint GetSecondPoint()const;
private:
	CPoint m_first;
	CPoint m_second;
	double m_length;
};

