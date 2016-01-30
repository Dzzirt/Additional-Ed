#pragma once
#include "SFML/System/Vector2.hpp"

class Canvas
{
public:
	Canvas(sf::Vector2f pos, sf::Vector2f size);
	~Canvas();
	Canvas() = default;
	sf::Vector2f GetPos();
	sf::Vector2f GetSize();
private:
	sf::Vector2f m_pos;
	sf::Vector2f m_size;

};

