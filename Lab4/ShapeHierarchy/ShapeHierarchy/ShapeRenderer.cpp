#include "stdafx.h"
#include "ShapeRenderer.h"



CShapeRenderer::CShapeRenderer(std::vector<std::shared_ptr<IShape>> const& shapes) :m_logicShapes(shapes)
{
}

void CShapeRenderer::Render()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes");
	while (window.isOpen())
	{
		window.clear(sf::Color::White);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		CDrawVisitor visitor;
		for (auto & logic : m_logicShapes)
		{
			logic->Accept(visitor);
			visitor.Draw(window);
		}
		window.display();
	}

}

