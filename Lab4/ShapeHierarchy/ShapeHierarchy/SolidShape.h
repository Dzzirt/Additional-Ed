#pragma once
#include "Shape.h"

class ISolidShape : public IShape
{
	virtual void SetFillColor(std::string const& color) = 0;
	virtual std::string GetFillColor()const = 0;
};