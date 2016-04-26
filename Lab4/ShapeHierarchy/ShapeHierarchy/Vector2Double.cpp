#include "stdafx.h"
#include "Vector2Double.h"

Vector2Double::Vector2Double(double x, double y)
	:x(x), y(y)
{

}


bool Vector2Double::operator==(Vector2Double const& other) const
{
	return (x == other.x) && (y == other.y);
}
