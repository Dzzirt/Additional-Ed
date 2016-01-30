#pragma once
#include "SFML/System/Vector2.hpp"

const unsigned WindowWidth = 800;
const unsigned WindowHeight = 600;

const sf::Vector2f DefaultShapeSize = sf::Vector2f(100.f, 100.f);

const sf::Vector2f MinShapeSize = sf::Vector2f(20.f, 20.f);

const sf::Vector2f CanvasSize = sf::Vector2f(640.f, 480.f);

enum ShapeType
{
	Rectangle,
	Triangle,
	Ellipse
};