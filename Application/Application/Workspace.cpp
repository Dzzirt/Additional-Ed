#include "WorkSpace.h"

Workspace::Workspace(const sf::Vector2f & pos, sf::Vector2f & size)
{
	m_canvasVisual.setPosition(pos);
	m_canvasVisual.setFillColor(sf::Color::White);
	m_canvasVisual.setOutlineThickness(1.f);
	m_canvasVisual.setOutlineColor(sf::Color::Black);
	m_canvasVisual.setSize(size);
}

Workspace::Workspace()
{
}

Workspace::~Workspace()
{
}

void Workspace::AddShape(std::shared_ptr<ShapeVisual> & shape)
{
	shape->SetPosition(sf::Vector2f(m_canvasVisual.getPosition().x + rand() % 300, m_canvasVisual.getPosition().y + rand() % 300));
	m_shapesVisual.push_back(shape);
}

void Workspace::RemoveSelectedShape()
{
	for (size_t i = 0; i < m_shapesVisual.size(); i++)
	{
		break;
	}
}

void Workspace::RemoveLastShape()
{
	if (m_shapesVisual.size() > 0)
	{
		m_shapesVisual.erase(m_shapesVisual.begin() + (m_shapesVisual.size() - 1));
	}
}

void Workspace::Draw(sf::RenderWindow & window)
{
	window.draw(m_canvasVisual);
	for (auto & shape : m_shapesVisual)
	{
		shape->Draw(window);
	}
}

std::vector<std::shared_ptr<ShapeVisual>>& Workspace::GetShapesVisual()
{
	return m_shapesVisual;
}

sf::RectangleShape& Workspace::GetCanvasVisual()
{
	return m_canvasVisual;
}
