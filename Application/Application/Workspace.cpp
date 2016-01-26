#include "WorkSpace.h"

Workspace::Workspace(const sf::Vector2f & pos, sf::Vector2f & size)
{
	canvas.setPosition(pos);
	canvas.setFillColor(sf::Color::White);
	canvas.setOutlineThickness(1.f);
	canvas.setOutlineColor(sf::Color::Black);
	canvas.setSize(size);
}

Workspace::Workspace()
{
}

Workspace::~Workspace()
{
}

void Workspace::AddShape(ShapeModel & shape)
{
	shape.SetPosition(sf::Vector2f(canvas.getPosition().x + rand() % 300, canvas.getPosition().y + rand() % 300));
	shapes.push_back(shape);
}

void Workspace::RemoveSelectedShape()
{
	for (size_t i = 0; i < shapes.size(); i++)
	{
		if (shapes[i].IsSelect())
		{
			shapes.erase(shapes.begin() + i);
		}
		break;
	}
}

void Workspace::RemoveLastShape()
{
	if (shapes.size() > 0)
	{
		shapes.erase(shapes.begin() + (shapes.size() - 1));
	}
}

void Workspace::Draw(sf::RenderWindow & window)
{
	window.draw(canvas);
	for (auto & shape : shapes)
	{
		shape.Draw(window);
	}
}