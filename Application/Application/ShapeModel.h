#pragma once
#include "SFML/Graphics.hpp"
#include "memory"
#include "AppConsts.h"
#include "EllipseShape.h"
#include "Frame.h"


class ShapeModel
{
public:
	ShapeModel();
	ShapeModel(std::shared_ptr<sf::CircleShape> shape);
	ShapeModel(std::shared_ptr<sf::RectangleShape> shape);
	ShapeModel(std::shared_ptr<EllipseShape> shape);
	~ShapeModel();

	void SetPosition(sf::Vector2f & pos);
	void SetSize(sf::Vector2f & size);
	void Draw(sf::RenderWindow & window);

	bool IsSelect();
private:
	sf::Vector2f pos;
	sf::Vector2f size;
	std::shared_ptr<sf::Shape> shape;
	Frame frame;
};

