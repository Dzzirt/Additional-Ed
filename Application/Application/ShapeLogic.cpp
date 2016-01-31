#include "ShapeLogic.h"


ShapeLogic::ShapeLogic(sf::Vector2f const& pos, sf::Vector2f const& size, ShapeType type)
	: m_bounds(pos, size), m_type(type), m_isSelect(false)
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
	Notify();
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

void ShapeLogic::Notify()
{
	m_onChange(m_bounds);
}

void ShapeLogic::RegisterObserver(IBoundsObserver & o)
{
	o.GetBoundsConnection() = m_onChange.connect(boost::bind(&IBoundsObserver::UpdateBounds, &o, _1));
	Notify();
}

void ShapeLogic::DeleteObserver(IBoundsObserver & o)
{
	o.GetBoundsConnection().disconnect();
}

