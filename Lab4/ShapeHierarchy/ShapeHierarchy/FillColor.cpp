#include "stdafx.h"
#include "FillColor.h"

CColorRGB CFillColor::GetFillColor() const
{
	return m_fillColor;
}

void CFillColor::SetFillColor(CColorRGB const& color)
{
	m_fillColor = color;
}

