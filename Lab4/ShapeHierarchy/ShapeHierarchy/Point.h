#pragma once
#include <utility>
#include "Shape.h"
#include "Vector2Double.h"

class CPoint : public IShape
{
public:
	CPoint() = delete;
	CPoint(double x, double y);
	Vector2Double GetPosition()const;
	void SetPosition(double x, double y);
	double GetArea()const override;
	double GetPerimeter()const override;
	std::string ToString()const override;
	void Accept(IVisitor & visitor) override;
private:
	Vector2Double m_pos;
};