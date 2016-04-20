#pragma once
#include "ColorRGB.h"

class CFillColor
{
public:
	CColorRGB GetFillColor()const;
	void SetFillColor(CColorRGB const& color);
private:
	CColorRGB m_fillColor;
};

