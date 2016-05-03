#pragma once
#include "FillColor.h"
#include "BorderColor.h"
#include "Point.h"

class CLineSegment :public IShape, public CBorderColor
{
public:
	CLineSegment() = delete;
	CLineSegment(CPoint first, CPoint second);
	double GetArea()const override;
	double GetPerimeter()const override;
	std::string ToString()const override;
	CPoint GetFirstPoint()const;
	CPoint GetSecondPoint()const;
	void Accept(IVisitor & visitor) override;
	//bool operator==(CLineSegment const& other);
private:
	CPoint m_first;
	CPoint m_second;
	double m_length;
};


bool operator==(CLineSegment const& lhs, CLineSegment const& rhs);
