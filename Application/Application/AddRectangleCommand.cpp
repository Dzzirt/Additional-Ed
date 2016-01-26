#include "AddRectangleCommand.h"


AddRectangleCommand::AddRectangleCommand(Workspace & workspace)
	: m_workspace(workspace)
{

}

AddRectangleCommand::~AddRectangleCommand()
{
}

void AddRectangleCommand::execute()
{
	m_workspace.AddShape(ShapeModel(std::make_shared<sf::RectangleShape>()));
}

void AddRectangleCommand::undo()
{
	m_workspace.RemoveLastShape();
}
