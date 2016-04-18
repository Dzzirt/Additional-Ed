#include "stdafx.h"
#include "ShapeRenderer.h"



CShapeRenderer::CShapeRenderer(std::vector<std::shared_ptr<IShape>> const& shapes) :m_logicShapes(shapes)
{
	CreateVisualShapes();
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
		for (auto & shape : m_visualShapes)
		{
			window.draw(*shape);
			
		}
		for (auto & line : m_visualLines)
		{
			window.draw(line);
		}

		window.display();
	}

}

void CShapeRenderer::CreateVisualShapes()
{
	for (auto & shape: m_logicShapes)
	{
		switch (shape->GetType())
		{
		case RECTANGLE:
		{
			CRectangle rect = dynamic_cast<CRectangle&>(*shape);
			auto visualShape = std::make_shared<sf::RectangleShape>();
			visualShape->setPosition((float)rect.GetPosition().first, (float)rect.GetPosition().second);
			visualShape->setSize(sf::Vector2f((float)rect.GetWidth(), (float)rect.GetHeight()));
			visualShape->setOutlineThickness(1);
			visualShape->setFillColor(sf::Color(rect.GetFillColor().r, rect.GetFillColor().g, rect.GetFillColor().b));
			visualShape->setOutlineColor(sf::Color(rect.GetBorderColor().r, rect.GetBorderColor().g, rect.GetBorderColor().b));
			m_visualShapes.push_back(visualShape);
			break;
		}
		case TRIANGLE:
		{
			CTriangle triangle = dynamic_cast<CTriangle&>(*shape);
			auto visualShape = std::make_shared<sf::ConvexShape>();
			visualShape->setPointCount(3);
			auto leftPoint = sf::Vector2f((float)triangle.GetLeftVertex().GetPosition().first,
				(float)triangle.GetLeftVertex().GetPosition().second);
			auto middlePoint = sf::Vector2f((float)triangle.GetMiddleVertex().GetPosition().first,
				(float)triangle.GetMiddleVertex().GetPosition().second);
			auto rightPoint = sf::Vector2f((float)triangle.GetRightVertex().GetPosition().first,
				(float)triangle.GetRightVertex().GetPosition().second);
			visualShape->setPoint(0, leftPoint);
			visualShape->setPoint(1, middlePoint);
			visualShape->setPoint(2, rightPoint);
			visualShape->setOutlineThickness(1);
			visualShape->setFillColor(sf::Color(triangle.GetFillColor().r, triangle.GetFillColor().g, triangle.GetFillColor().b));
			visualShape->setOutlineColor(sf::Color(triangle.GetBorderColor().r, triangle.GetBorderColor().g, triangle.GetBorderColor().b));
			m_visualShapes.push_back(visualShape);
			break;
		}
		case LINE_SEGMENT:
		{
			CLineSegment line = dynamic_cast<CLineSegment&>(*shape);
			auto leftPoint = sf::Vector2f((float)line.GetFirstPoint().GetPosition().first,
				(float)line.GetFirstPoint().GetPosition().second);
			auto rightPoint = sf::Vector2f((float)line.GetSecondPoint().GetPosition().first,
				(float)line.GetSecondPoint().GetPosition().second);
			sf::VertexArray visualLine(sf::Lines, 2);
			visualLine[0].position = leftPoint;
			visualLine[1].position = rightPoint;
			visualLine[0].color = sf::Color(line.GetBorderColor().r, line.GetBorderColor().g, line.GetBorderColor().b);
			m_visualLines.push_back(visualLine);
			visualLine[1].color = sf::Color(line.GetBorderColor().r, line.GetBorderColor().g, line.GetBorderColor().b);
			m_visualLines.push_back(visualLine);
			break;
		}
		case CIRCLE:
		{
			CCircle circle = dynamic_cast<CCircle&>(*shape);
			auto visualShape = std::make_shared<sf::CircleShape>();
			visualShape->setRadius(circle.GetRadius());
			visualShape->setPosition(sf::Vector2f(circle.GetCenter().GetPosition().first, circle.GetCenter().GetPosition().second));
			visualShape->setFillColor(sf::Color(circle.GetFillColor().r, circle.GetFillColor().g, circle.GetFillColor().b));
			visualShape->setOutlineColor(sf::Color(circle.GetBorderColor().r, circle.GetBorderColor().g, circle.GetBorderColor().b));
			visualShape->setOrigin(sf::Vector2f(circle.GetRadius(), circle.GetRadius()));
			m_visualShapes.push_back(visualShape);
		}
		default:
			break;
		}
	}
}

CShapeRenderer::~CShapeRenderer()
{
}
