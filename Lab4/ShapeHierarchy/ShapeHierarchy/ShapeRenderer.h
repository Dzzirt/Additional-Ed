#pragma once
#include <vector>
#include <memory>
#include "Shape.h"
#include "DrawVisitor.h"
#include <SFML/Graphics.hpp>

class CShapeRenderer
{
public:
	CShapeRenderer() = delete;
	CShapeRenderer(std::vector<std::shared_ptr<IShape>> const& shapes);
	void Render();
private:
	std::vector<std::shared_ptr<IShape>> m_logicShapes;
};

