#pragma once
#include "SFML/Graphics.hpp"
#include "memory"
#include "AppConsts.h"
#include "EllipseShape.h"
#include "Frame.h"


class ShapeVisual
{
public:
	ShapeVisual();
	ShapeVisual(std::shared_ptr<sf::CircleShape> & shape);
	ShapeVisual(std::shared_ptr<sf::RectangleShape> & shape);
	ShapeVisual(std::shared_ptr<EllipseShape> & shape);
	~ShapeVisual();

	void SetPosition(const sf::Vector2f & pos);
	void SetSize(const sf::Vector2f & size);
	void Draw(sf::RenderWindow & window);
	void Update(const sf::Vector2f & pos, const sf::Vector2f & size);
private:
	std::shared_ptr<sf::Shape> m_shape;
};

