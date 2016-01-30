#include "ShapeLogic.h"


ShapeLogic::ShapeLogic(sf::Vector2f const& pos, sf::Vector2f const& size, ShapeType type)
	: m_pos(pos), m_size(size), m_type(type), m_isSelect(false)
{
}


ShapeLogic::~ShapeLogic()
{
}

void ShapeLogic::SetSize(sf::Vector2f const& size)
{
	m_size = size;
	m_onChange(m_size, m_pos);
}

void ShapeLogic::SetPosition(sf::Vector2f const& pos)
{
	m_pos = pos;
	m_onChange(m_size, m_pos);
}

ShapeType ShapeLogic::GetType()
{
	return m_type;
}

sf::Vector2f ShapeLogic::GetPosition()
{
	return m_pos;
}

sf::Vector2f ShapeLogic::GetSize()
{
	return m_size;
}


