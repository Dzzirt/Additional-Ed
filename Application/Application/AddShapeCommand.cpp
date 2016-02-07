#include "AddShapeCommand.h"

AddShapeCommand::AddShapeCommand(IShapeCreator & creator, ShapeType type)
	: m_type(type), m_creator(creator)
{
	float  border = (WindowWidth - CanvasSize.x) / 2.f;
	auto & canvasPos = sf::Vector2f(border, WindowHeight - CanvasSize.y - border);
	auto & defaultShapePos = sf::Vector2f(canvasPos + CanvasSize / 2.f - DefaultShapeSize / 2.f);
	sf::FloatRect & bounds = sf::FloatRect(defaultShapePos, DefaultShapeSize);
	m_logic = std::make_shared<ShapeLogic>(bounds, m_type);
	if (m_type == Rectangle)
	{
		m_visual = std::make_shared<ShapeVisual>(std::make_shared<sf::RectangleShape>());
	}
	else if (m_type == Ellipse)
	{
		m_visual = std::make_shared<ShapeVisual>(std::make_shared<EllipseShape>());
	}
	else if (m_type == Triangle)
	{
		m_visual = std::make_shared<ShapeVisual>(std::make_shared<sf::ConvexShape>());
	}
}

AddShapeCommand::~AddShapeCommand()
{

}

void AddShapeCommand::execute()
{
	m_creator.AddShape(m_logic, m_visual);
}

void AddShapeCommand::undo()
{
	m_creator.DeleteShape(*m_logic);
}

