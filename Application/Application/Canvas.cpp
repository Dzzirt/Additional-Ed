#include "Canvas.h"


Canvas::Canvas(sf::Vector2f pos, sf::Vector2f size)
	: m_pos(pos), m_size(size)
{
}


sf::Vector2f Canvas::GetPos()
{
	return m_pos;
}

sf::Vector2f Canvas::GetSize()
{
	return m_size;
}

Canvas::~Canvas()
{
}
