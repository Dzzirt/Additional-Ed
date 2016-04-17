#pragma once
#include <string>

class IShape
{
public:
	virtual double GetArea()const = 0;
	virtual double GetPerimeter()const = 0;
	virtual std::string GetBorderColor()const = 0;
	virtual void SetBorderColor(std::string const& color) = 0;
	virtual std::string ToString()const = 0;
};