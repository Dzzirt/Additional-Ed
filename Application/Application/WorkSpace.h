#pragma once
#include "ShapeModel.h"

class Workspace
{
public:
	Workspace();
	Workspace(const sf::Vector2f & pos, sf::Vector2f & size);
	~Workspace();

	void AddShape(ShapeModel & shape);
	void RemoveSelectedShape();
	void RemoveLastShape();
	void Draw(sf::RenderWindow & window);
private:
	std::vector<ShapeModel> shapes;
	sf::RectangleShape canvas;
};
