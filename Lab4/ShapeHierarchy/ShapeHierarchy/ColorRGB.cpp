#include "stdafx.h"
#include "ColorRGB.h"

CColorRGB::CColorRGB()
{

}

CColorRGB::CColorRGB(unsigned char r, unsigned char g, unsigned 
	char b)
	:r(r), g(g), b(b)
{
}

bool CColorRGB::operator==(CColorRGB const& other) const
{
	return (r == other.r) && (g == other.g) && (b == other.b);
}

