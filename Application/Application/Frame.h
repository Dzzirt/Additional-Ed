#pragma once
#include "SFML/Graphics.hpp"

enum Corners
{
	UpperLeft,
	UpperRight,
	BottomRight,
	BottomLeft
};

class Frame
{
public:
	Frame();
	Frame(const sf::Vector2f & pos, sf::Vector2f & size);
	~Frame();

	void SetPosition(const sf::Vector2f & pos);
	void SetSize(sf::Vector2f & size);
	sf::CircleShape GetPoint(Corners & corner);
	void SetVisible(bool flag);
	bool GetVisible();
	void Draw(sf::RenderWindow & window);
	sf::FloatRect GetGlobalBounds();
private:
	sf::RectangleShape rect;
	std::vector<sf::CircleShape> points;
	bool isVisible;
	void SetPointsOnCorners(sf::FloatRect & rect);
};

