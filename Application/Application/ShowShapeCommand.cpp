#include "ShowShapeCommand.h"

ShowShapeCommand::ShowShapeCommand(ApplicationView & view, size_t index)
	: m_view(view), m_index(index)
{

}

ShowShapeCommand::~ShowShapeCommand()
{

}

void ShowShapeCommand::execute()
{
	m_view.GetWorkspace().GetShapesVisual().at(m_index)->SetVisible(true);
	m_view.GetFrame().SetVisible(true);
}

void ShowShapeCommand::undo()
{
	m_view.GetWorkspace().GetShapesVisual().at(m_index)->SetVisible(false);
	m_view.GetFrame().SetVisible(false);
}

