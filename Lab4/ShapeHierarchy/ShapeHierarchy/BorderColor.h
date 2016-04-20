#pragma once
#include "ColorRGB.h"

class CBorderColor
{
public:
	CColorRGB GetBorderColor()const;
	void SetBorderColor(CColorRGB const& color);
private:
	CColorRGB m_borderColor;
};

