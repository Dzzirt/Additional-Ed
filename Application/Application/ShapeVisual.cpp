#include "ShapeVisual.h"
ShapeVisual::ShapeVisual()
{
}

ShapeVisual::ShapeVisual(std::shared_ptr<sf::ConvexShape> & shape)
	: m_isVisible(true)
{
	shape->setPointCount(3);
 	shape->setPoint(0, sf::Vector2f(0.5f, 0.f));
 	shape->setPoint(1, sf::Vector2f(1.f, 1.f));
 	shape->setPoint(2, sf::Vector2f(0.f, 1.f));
	shape->setFillColor(sf::Color::Yellow);
	shape->setOutlineThickness(1);
	shape->setOutlineColor(sf::Color::Black);
	this->m_shape = shape;
}

ShapeVisual::ShapeVisual(std::shared_ptr<sf::RectangleShape> & shape)
	: m_isVisible(true)
{
	shape->setFillColor(sf::Color::Blue);
	shape->setOutlineThickness(1);
	shape->setOutlineColor(sf::Color::Black);
	shape->setSize(sf::Vector2f(1.f, 1.f));
	this->m_shape = shape;
}

ShapeVisual::ShapeVisual(std::shared_ptr<EllipseShape> & shape)
	: m_isVisible(true)
{
	shape->setFillColor(sf::Color::Magenta);
	shape->setOutlineThickness(1);
	shape->setOutlineColor(sf::Color::Black);
	shape->setRadius(sf::Vector2f(0.5f, 0.5f));
	this->m_shape = shape;
}

void ShapeVisual::Draw(sf::RenderWindow & window)
{
	if (m_isVisible)
	{
		window.draw(*m_shape);
	}
	
}

void ShapeVisual::UpdateBounds(const sf::FloatRect & bounds, const sf::Vector2f & origin)
{
	SetOrigin(origin);
	SetPosition(sf::Vector2f(bounds.left, bounds.top));
	SetSize(sf::Vector2f(bounds.width, bounds.height));
}

boost::signals2::connection& ShapeVisual::GetBoundsConnection()
{
	return m_boundsConnection;
}

void ShapeVisual::ProcessEvents(sf::Event event)
{
	sf::Vector2f mousePos = sf::Vector2f(float(event.mouseButton.x), float(event.mouseButton.y));
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_shape->getGlobalBounds().contains(mousePos))
	{
		HandleOnClick();
	}
}

boost::signals2::connection ShapeVisual::DoOnClick(const ButtonClickSignal::slot_type & handler)
{
	return m_onClick.connect(handler);
}

void ShapeVisual::HandleOnClick()
{
	m_onClick(m_index);
}

void ShapeVisual::SetOrigin(const sf::Vector2f & origin)
{
	m_shape->setOrigin(origin);
}

ShapeVisual::~ShapeVisual()
{
}

void ShapeVisual::SetPosition(const sf::Vector2f & pos)
{
	m_shape->setPosition(pos);
}

void ShapeVisual::SetSize(const sf::Vector2f & size)
{
	m_shape->setScale(size.x, size.y);
	m_shape->setOutlineThickness(1 / m_shape->getScale().x);
}

void ShapeVisual::SetIndex(size_t index)
{
	m_index = index;
}

void ShapeVisual::SetVisible(bool flag)
{
	m_isVisible = flag;
}

size_t ShapeVisual::GetIndex()
{
	return m_index;
}

bool ShapeVisual::GetVisible()
{
	return m_isVisible;
}

