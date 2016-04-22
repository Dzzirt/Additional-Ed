#include "stdafx.h"
#include "Vector2Double.h"


bool operator==(Vector2Double const& vector1, Vector2Double const& vector2)
{
	return (vector1.x == vector2.x) && (vector1.y == vector2.y);
}

Vector2Double::Vector2Double(double x, double y)
	:x(x), y(y)
{

}