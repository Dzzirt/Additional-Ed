#pragma once
#include "SolidShape.h"
#include "Point.h"
#include "FillColor.h"
#include "BorderColor.h"

class CCircle : public IShape, public CBorderColor, public CFillColor
{
public:
	CCircle() = delete;
	CCircle(CPoint center, double radius);
	double GetArea()const override;
	double GetPerimeter()const override;
	std::string ToString()const override;
	double GetRadius()const;
	CPoint GetCenter()const;
	Shapes GetType()const override;
private:
	CPoint m_center;
	double m_radius;
};

