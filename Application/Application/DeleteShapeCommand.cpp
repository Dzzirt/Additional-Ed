#include "DeleteShapeCommand.h"

DeleteShapeCommand::DeleteShapeCommand(IShapeCreator & creator, std::shared_ptr<ShapeLogic> & logic,
	std::shared_ptr<ShapeVisual> & visual)
	: m_logic(logic), m_creator(creator), m_visual(visual)
{

}

DeleteShapeCommand::~DeleteShapeCommand()
{

}

void DeleteShapeCommand::execute()
{
	m_index = m_creator.DeleteShape(*m_logic);
}

void DeleteShapeCommand::undo()
{
	m_creator.AddShape(m_logic, m_visual, m_index);
}

