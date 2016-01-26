#include "ShapeModel.h"

ShapeModel::ShapeModel()
{
}

ShapeModel::ShapeModel(std::shared_ptr<sf::CircleShape> shape)
{
	size = DefaultShapeSize;
	shape->setRadius(size.x);
	shape->setPointCount(3);
	shape->setFillColor(sf::Color::Blue);
	shape->setOrigin(shape->getGlobalBounds().width / 2.f, shape->getGlobalBounds().height / 2.f);
	frame = Frame(sf::Vector2f(shape->getGlobalBounds().left, shape->getGlobalBounds().top), size);
	this->shape = shape;
	SetSize(size);
}

ShapeModel::ShapeModel(std::shared_ptr<sf::RectangleShape> shape)
{
	size = DefaultShapeSize;
	shape->setFillColor(sf::Color::Blue);
	shape->setSize(size);
	frame = Frame(shape->getPosition(), size);
	shape->setOrigin(shape->getSize() / 2.f);

	this->shape = shape;
}

ShapeModel::ShapeModel(std::shared_ptr<EllipseShape> shape)
{
	size = DefaultShapeSize;
	shape->setFillColor(sf::Color::Blue);
	frame = Frame(shape->getPosition(), size);
	shape->setOrigin(shape->getRadius());
	shape->setRadius(sf::Vector2f(30, 20));
	this->shape = shape;
	SetSize(size);
}

void ShapeModel::SetPosition(sf::Vector2f & pos)
{
	shape->setPosition(pos);
	sf::FloatRect frameBounds = shape->getGlobalBounds();
	frame.SetPosition(sf::Vector2f(frameBounds.left,
		frameBounds.top));
	

}

void ShapeModel::SetSize(sf::Vector2f & size)
{
	frame.SetSize(size);
	sf::FloatRect shapeBounds = shape->getGlobalBounds();
	shape->setScale(size.x / shapeBounds.width,
		size.y / shapeBounds.height);
}

void ShapeModel::Draw(sf::RenderWindow & window)
{
	window.draw(*shape);
	frame.Draw(window);
}

bool ShapeModel::IsSelect()
{
	return frame.GetVisible();
}
ShapeModel::~ShapeModel()
{
}


