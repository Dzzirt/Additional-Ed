#include "stdafx.h"
#include "DrawVisitor.h"
#include "LineSegment.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

void CDrawVisitor::Visit(CLineSegment & line)
{
	auto leftPoint = sf::Vector2f((float)line.GetFirstPoint().GetPosition().first,
		(float)line.GetFirstPoint().GetPosition().second);
	auto rightPoint = sf::Vector2f((float)line.GetSecondPoint().GetPosition().first,
		(float)line.GetSecondPoint().GetPosition().second);
	auto visualLine = sf::VertexArray(sf::Lines, 2);
	visualLine[0].position = leftPoint;
	visualLine[1].position = rightPoint;
	visualLine[0].color = sf::Color(line.GetBorderColor().r, line.GetBorderColor().g, line.GetBorderColor().b);
	visualLine[1].color = sf::Color(line.GetBorderColor().r, line.GetBorderColor().g, line.GetBorderColor().b);
	m_drawable = std::make_unique<sf::VertexArray>(visualLine);
}

void CDrawVisitor::Visit(CTriangle & triangle)
{
	auto visualShape = std::make_unique<sf::ConvexShape>();
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
	m_drawable = std::move(visualShape);
}

void CDrawVisitor::Visit(CRectangle & rectangle)
{
	auto visualRect = std::make_unique<sf::RectangleShape>();
	visualRect->setPosition((float)rectangle.GetPosition().first, (float)rectangle.GetPosition().second);
	visualRect->setSize(sf::Vector2f((float)rectangle.GetWidth(), (float)rectangle.GetHeight()));
	visualRect->setOutlineThickness(1);
	visualRect->setFillColor(sf::Color(rectangle.GetFillColor().r, rectangle.GetFillColor().g, rectangle.GetFillColor().b));
	visualRect->setOutlineColor(sf::Color(rectangle.GetBorderColor().r, rectangle.GetBorderColor().g, rectangle.GetBorderColor().b));
	m_drawable = std::move(visualRect);
}

void CDrawVisitor::Visit(CCircle & circle)
{
	auto visualShape = std::make_unique<sf::CircleShape>();
	visualShape->setRadius(static_cast<float>(circle.GetRadius()));
	visualShape->setPosition(sf::Vector2f(static_cast<float>(circle.GetCenter().GetPosition().first), 
		static_cast<float>(circle.GetCenter().GetPosition().second)));
	visualShape->setFillColor(sf::Color(circle.GetFillColor().r, circle.GetFillColor().g, circle.GetFillColor().b));
	visualShape->setOutlineThickness(1);
	visualShape->setOutlineColor(sf::Color(circle.GetBorderColor().r, circle.GetBorderColor().g, circle.GetBorderColor().b));
	visualShape->setOrigin(sf::Vector2f(static_cast<float>(circle.GetRadius()), static_cast<float>(circle.GetRadius())));
	m_drawable = std::move(visualShape);
}

void CDrawVisitor::Draw(sf::RenderWindow & window)
{
	window.draw(*m_drawable);
}
