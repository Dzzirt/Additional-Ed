#pragma once
#include "ShapeVisual.h"

class Workspace
{
public:
	Workspace();
	Workspace(const sf::Vector2f & pos, sf::Vector2f & size);
	~Workspace();

	void AddShape(std::shared_ptr<ShapeVisual> & shape);
	void RemoveSelectedShape();
	void RemoveLastShape();
	void Draw(sf::RenderWindow & window);
	std::vector<std::shared_ptr<ShapeVisual>>& GetShapesVisual();
	sf::RectangleShape& GetCanvasVisual();
private:
	std::vector<std::shared_ptr<ShapeVisual>> m_shapesVisual;
	sf::RectangleShape m_canvasVisual;
};
