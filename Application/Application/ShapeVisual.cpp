#include "ShapeVisual.h"

ShapeVisual::ShapeVisual()
{
}

ShapeVisual::ShapeVisual(std::shared_ptr<sf::ConvexShape> & shape)
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
{
	shape->setFillColor(sf::Color::Blue);
	shape->setOutlineThickness(1);
	shape->setOutlineColor(sf::Color::Black);
	shape->setSize(sf::Vector2f(1.f, 1.f));
	this->m_shape = shape;
}

ShapeVisual::ShapeVisual(std::shared_ptr<EllipseShape> & shape)
{
	shape->setFillColor(sf::Color::Magenta);
	shape->setOutlineThickness(1);
	shape->setOutlineColor(sf::Color::Black);
	shape->setRadius(sf::Vector2f(0.5f, 0.5f));
	this->m_shape = shape;
}

void ShapeVisual::Draw(sf::RenderWindow & window)
{
	window.draw(*m_shape);
}

void ShapeVisual::UpdateBounds(const sf::FloatRect & bounds)
{
	SetPosition(sf::Vector2f(bounds.left, bounds.top));
	SetSize(sf::Vector2f(bounds.width, bounds.height));
}

boost::signals2::connection& ShapeVisual::GetBoundsConnection()
{
	return m_boundsConnection;
}

void ShapeVisual::ProcessEvents(sf::Event event)
{
	sf::Vector2f mousePos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_shape->getGlobalBounds().contains(mousePos))
	{
		Notify();
	}
}

void ShapeVisual::RegisterObserver(IShapeClickObserver & o)
{
	o.GetShapeClickConnection() = m_onClick.connect(boost::bind(&IShapeClickObserver::UpdateOnShapeClick, &o, _1));
}

void ShapeVisual::DeleteObserver(IShapeClickObserver & o)
{
	o.GetShapeClickConnection().disconnect();
}

void ShapeVisual::Notify()
{
	m_onClick(m_index);
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

