#include "AddEllipseCommand.h"


AddEllipseCommand::AddEllipseCommand(Workspace & workspace)
	: m_workspace(workspace)
{

}

AddEllipseCommand::~AddEllipseCommand()
{
}

void AddEllipseCommand::execute()
{
	m_workspace.AddShape(ShapeModel(std::make_shared<EllipseShape>()));
}

void AddEllipseCommand::undo()
{
	m_workspace.RemoveLastShape();
}