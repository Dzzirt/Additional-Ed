#pragma once

class CColorRGB
{
public:
	CColorRGB();
	CColorRGB(unsigned char r, unsigned char g, unsigned char b);
	unsigned char r;
	unsigned char g;
	unsigned char b;

	bool operator==(CColorRGB const& other)const;
};



