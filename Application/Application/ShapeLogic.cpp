#include "ShapeLogic.h"
#include "iostream"

ShapeLogic::ShapeLogic(sf::FloatRect const& bounds, ShapeType type)
	: m_bounds(bounds), m_type(type), m_isSelect(false), m_origin(sf::Vector2f(0.f, 0.f))
{
}


ShapeLogic::~ShapeLogic()
{
}

void ShapeLogic::SetSize(sf::Vector2f const& size)
{
	m_bounds.width = size.x;
	m_bounds.height = size.y;
}

void ShapeLogic::SetPosition(sf::Vector2f const& pos)
{
	m_bounds.left = pos.x;
	m_bounds.top = pos.y;
	HandleChange();
}

void ShapeLogic::SetSelected(bool flag)
{
	m_isSelect = flag;
}

ShapeType ShapeLogic::GetType()
{
	return m_type;
}


sf::FloatRect ShapeLogic::GetBounds()
{
	return m_bounds;
}

sf::Vector2f ShapeLogic::GetPosition()
{
	return sf::Vector2f(m_bounds.left, m_bounds.top);
}

sf::Vector2f ShapeLogic::GetSize()
{
	return sf::Vector2f(m_bounds.width, m_bounds.height);
}

void ShapeLogic::HandleChange()
{
	m_onChange(m_bounds, m_origin);
}

boost::signals2::connection ShapeLogic::DoOnChange(const BoundsChangeSignal::slot_type & handler)
{
	boost::signals2::connection con = m_onChange.connect(handler);
	HandleChange();
	return con;
}

void ShapeLogic::SetOrigin(const sf::Vector2f & pos)
{
	m_origin = pos;
	HandleChange();
}

