#include "stdafx.h"
#include "BorderColor.h"


CColorRGB CBorderColor::GetBorderColor() const
{
	return m_borderColor;
}

void CBorderColor::SetBorderColor(CColorRGB const& color)
{
	m_borderColor = color;
}

