#pragma once
#include <vector>
#include <memory>
#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "LineSegment.h"
#include <SFML/Graphics.hpp>

class CShapeRenderer
{
public:
	CShapeRenderer() = delete;
	CShapeRenderer(std::vector<std::shared_ptr<IShape>> const& shapes);
	void Render();
	void CreateVisualShapes();
	~CShapeRenderer();
private:
	std::vector<std::shared_ptr<IShape>> m_logicShapes;
	std::vector<std::shared_ptr<sf::Shape>> m_visualShapes;
	std::vector<sf::VertexArray> m_visualLines;
};

