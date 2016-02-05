#include "SetShapePositionCommand.h"


SetShapePositionCommand::SetShapePositionCommand(ShapeLogic & shape, sf::Vector2f pos)
	: m_shape(shape), m_currPos(pos), m_prevPos(m_shape.GetPosition())
{

}

SetShapePositionCommand::~SetShapePositionCommand()
{
}

void SetShapePositionCommand::execute()
{
	m_shape.SetPosition(m_currPos);
}

void SetShapePositionCommand::undo()
{
	m_shape.SetPosition(m_prevPos);

}