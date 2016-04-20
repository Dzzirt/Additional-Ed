#pragma once
#include <string>
#include "ColorRGB.h"
enum Shapes
{
	LINE_SEGMENT,
	RECTANGLE,
	TRIANGLE,
	CIRCLE,
	POINT
};
class IShape
{
public:
	virtual double GetArea()const = 0;
	virtual double GetPerimeter()const = 0;
	virtual std::string ToString()const = 0;
	virtual Shapes GetType()const = 0;
	virtual ~IShape() = default;
};