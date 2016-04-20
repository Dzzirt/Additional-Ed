#pragma once
#include "FillColor.h"
#include "BorderColor.h"
#include "Point.h"

class CRectangle : public IShape, public CFillColor, public CBorderColor
{
public:
	CRectangle() = delete;
	CRectangle(CPoint upperLeft, double width, double height);
	double GetArea()const override;
	double GetPerimeter()const override;
	double GetWidth()const;
	double GetHeight()const;
	std::pair<double, double> GetPosition()const;
	std::string ToString()const override;
	void Accept(IVisitor & visitor) override;
private:
	CPoint m_upperLeftCorner;
	double m_width;
	double m_height;
};

