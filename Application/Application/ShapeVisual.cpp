#include "ShapeVisual.h"

ShapeVisual::ShapeVisual()
{
}

ShapeVisual::ShapeVisual(std::shared_ptr<sf::CircleShape> & shape)
{
	shape->setPointCount(3);
	shape->setFillColor(sf::Color::Yellow);
	shape->setOutlineThickness(1);
	shape->setOutlineColor(sf::Color::Black);
	shape->setOrigin(shape->getGlobalBounds().width / 2.f, shape->getGlobalBounds().height / 2.f);
	shape->setRadius(DefaultShapeSize.x);
	this->m_shape = shape;
}

ShapeVisual::ShapeVisual(std::shared_ptr<sf::RectangleShape> & shape)
{
	shape->setFillColor(sf::Color::Blue);
	shape->setOrigin(shape->getSize() / 2.f);
	shape->setOutlineThickness(1);
	shape->setOutlineColor(sf::Color::Black);
	shape->setSize(DefaultShapeSize);
	this->m_shape = shape;
}

ShapeVisual::ShapeVisual(std::shared_ptr<EllipseShape> & shape)
{
	shape->setFillColor(sf::Color::Magenta);
	shape->setOrigin(shape->getRadius());
	shape->setOutlineThickness(1);
	shape->setOutlineColor(sf::Color::Black);
	shape->setRadius(DefaultShapeSize);
	this->m_shape = shape;
}

/*void ShapeVisual::SetPosition(sf::Vector2f & pos)
{
	shape->setPosition(pos);
	sf::FloatRect frameBounds = shape->getGlobalBounds();
	frame.SetPosition(sf::Vector2f(frameBounds.left,
		frameBounds.top));
	

}

void ShapeVisual::SetSize(sf::Vector2f & size)
{
	frame.SetSize(size);
	sf::FloatRect shapeBounds = shape->getGlobalBounds();
	shape->setScale(size.x / shapeBounds.width,
		size.y / shapeBounds.height);
}*/

void ShapeVisual::Draw(sf::RenderWindow & window)
{
	window.draw(*m_shape);
}

void ShapeVisual::Update(const sf::Vector2f & pos, const sf::Vector2f & size)
{
	SetPosition(pos);
	SetSize(size);
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
	float width = m_shape->getGlobalBounds().width;
	float height = m_shape->getGlobalBounds().height;
	m_shape->setScale(size.x / width, size.y / height);
}

