#pragma once
#include "FillColor.h"
#include "BorderColor.h"
#include "Point.h"

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
	void Accept(IVisitor & visitor) override;
private:
	CPoint m_center;
	double m_radius;
};

