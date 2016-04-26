#pragma once

struct Vector2Double
{
	Vector2Double() = delete;
	Vector2Double(double x, double y);
	bool operator==(Vector2Double const& other)const;
	double x;
	double y;
};

