#pragma once
#include "Command.h"
#include "ShapeLogic.h"

class SetShapePositionCommand : public ICommand
{
public:
	SetShapePositionCommand(ShapeLogic & shape, sf::Vector2f pos);
	~SetShapePositionCommand();
	void execute()override;
	void undo()override;
private:
	ShapeLogic & m_shape;
	sf::Vector2f m_prevPos;
	sf::Vector2f m_currPos;
};

