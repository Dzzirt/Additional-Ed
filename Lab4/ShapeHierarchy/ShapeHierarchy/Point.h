#pragma once
#include <utility>
#include "Shape.h"

class CPoint : public IShape
{
public:
	CPoint() = delete;
	CPoint(double x, double y);
	std::pair<double, double> GetPosition()const;
	void SetPosition(double x, double y);
	double GetArea()const override;
	double GetPerimeter()const override;
	std::string ToString()const override;
	void Accept(IVisitor & visitor) override;
private:
	std::pair<double, double> m_pos;
};