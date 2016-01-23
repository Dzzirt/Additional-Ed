#include "SFML/Graphics.hpp"
#include "memory"
#include "AppConsts.h"
#include "EllipseShape.h"
#include "Frame.h"
class ShapeModel
{
public:
	ShapeModel();
	ShapeModel(std::shared_ptr<sf::CircleShape> shape);
	ShapeModel(std::shared_ptr<sf::RectangleShape> shape);
	ShapeModel(std::shared_ptr<EllipseShape> shape);
	~ShapeModel();

	void SetPosition(sf::Vector2f & pos);
private:
	sf::Vector2f pos;
	sf::Vector2f size;
	std::shared_ptr<sf::Shape> shape;
	Frame frame;
};

ShapeModel::ShapeModel()
{
}

ShapeModel::ShapeModel(std::shared_ptr<sf::CircleShape> shape)
{
	size = DefaultShapeSize;
	shape->setRadius(size.x);
	frame = Frame(shape->getPosition(), size);
	shape->setOrigin(shape->getRadius(), shape->getRadius());
	this->shape = shape;
}

ShapeModel::ShapeModel(std::shared_ptr<sf::RectangleShape> shape)
{
	size = DefaultShapeSize;
	frame = Frame(shape->getPosition(), size);
	shape->setOrigin(shape->getSize() / 2.f);
	shape->setSize(size);
	this->shape = shape;
}

ShapeModel::ShapeModel(std::shared_ptr<EllipseShape> shape)
{
	size = DefaultShapeSize;
	frame = Frame(shape->getPosition(), size);
	shape->setOrigin(shape->getRadius());
	shape->setRadius(size);
	this->shape = shape;
}

void ShapeModel::SetPosition(sf::Vector2f & pos)
{
	shape->setPosition(pos);
	sf::FloatRect shapeBounds = shape->getGlobalBounds();
	frame.SetPosition(sf::Vector2f(shapeBounds.left, shapeBounds.top));
}

ShapeModel::~ShapeModel()
{
}


