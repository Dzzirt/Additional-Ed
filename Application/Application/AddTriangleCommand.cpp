#include "AddTriangleCommand.h"


AddTriangleCommand::AddTriangleCommand(Workspace & workspace)
	: m_workspace(workspace)
{

}

AddTriangleCommand::~AddTriangleCommand()
{
}

void AddTriangleCommand::execute()
{
	m_workspace.AddShape(ShapeModel(std::make_shared<sf::CircleShape>()));
}

void AddTriangleCommand::undo()
{
	m_workspace.RemoveLastShape();
}