#include "ShapeVisual.h"
#include "iostream"

// ConvexShapes
ShapeVisual::ShapeVisual()
{
}

ShapeVisual::ShapeVisual(std::shared_ptr<sf::ConvexShape> & shape)
	: m_isVisible(true), m_isPressed(false)
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
	: m_isVisible(true), m_isPressed(false)
{
	shape->setFillColor(sf::Color::Blue);
	shape->setOutlineThickness(1);
	shape->setOutlineColor(sf::Color::Black);
	shape->setSize(sf::Vector2f(1.f, 1.f));
	this->m_shape = shape;
}

ShapeVisual::ShapeVisual(std::shared_ptr<EllipseShape> & shape)
	: m_isVisible(true), m_isPressed(false)
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

void ShapeVisual::UpdateBounds(const sf::FloatRect & bounds)
{
	SetPosition(sf::Vector2f(bounds.left, bounds.top));
	SetSize(sf::Vector2f(bounds.width, bounds.height));
}

boost::signals2::connection& ShapeVisual::GetBoundsConnection()
{
	return m_boundsConnection;
}

bool ShapeVisual::ProcessEvents(sf::Event event)
{
	sf::Vector2f mousePos = sf::Vector2f(float(event.mouseButton.x), float(event.mouseButton.y));
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_shape->getGlobalBounds().contains(mousePos))
	{
		m_isPressed = true;
		return true;
	}
	if (event.type == event.MouseButtonReleased && m_isPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			m_isPressed = false;
			HandleOnClick();
			return true;
		}
	}
	return false;
}

boost::signals2::connection ShapeVisual::DoOnClick(const ButtonClickSignal::slot_type & handler)
{
	return m_onClick.connect(handler);
}

void ShapeVisual::HandleOnClick()
{
	m_onClick(*this);
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

void ShapeVisual::SetVisible(bool flag)
{
	m_isVisible = flag;
}

bool ShapeVisual::GetVisible()
{
	return m_isVisible;
}

