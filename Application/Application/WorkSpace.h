#pragma once
#include "ShapeVisual.h"

class Workspace
{
public:
	Workspace();
	Workspace(const sf::Vector2f & pos, sf::Vector2f & size);
	~Workspace();

	void AddShape(std::shared_ptr<ShapeVisual> & shape, size_t index);
	void RemoveSelectedShape();
	void RemoveLastShape();
	void Draw(sf::RenderWindow & window);
	size_t GetShapesCount();
	std::vector<std::shared_ptr<ShapeVisual>>& GetShapesVisual();
	sf::RectangleShape& GetCanvasVisual();
	void ProcessEvents(sf::Event event);
private:
	std::vector<std::shared_ptr<ShapeVisual>> m_shapesVisual;
	sf::RectangleShape m_canvasVisual;
	int FindPos(std::shared_ptr<ShapeVisual> shapeVisual);
};
