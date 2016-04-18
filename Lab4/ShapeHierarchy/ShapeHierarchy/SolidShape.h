#pragma once
#include "Shape.h"

class ISolidShape : public IShape
{
	virtual void SetFillColor(CColorRGB const& color) = 0;
	virtual CColorRGB GetFillColor()const = 0;
};