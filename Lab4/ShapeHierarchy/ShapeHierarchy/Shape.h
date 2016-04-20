#pragma once
#include <string>
#include "ColorRGB.h"
#include "Element.h"
class IShape : public IElement
{
public:
	virtual double GetArea()const = 0;
	virtual double GetPerimeter()const = 0;
	virtual std::string ToString()const = 0;
	virtual ~IShape() = default;
};