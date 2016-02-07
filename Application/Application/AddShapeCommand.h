#pragma once
#include "Command.h"
#include "AppConsts.h"
#include "ShapeLogic.h"
#include "ShapeVisual.h"
#include "memory"
#include "ShapeCreator.h"

class AddShapeCommand : public ICommand
{
public:
	AddShapeCommand(IShapeCreator & creator, ShapeType type);
	~AddShapeCommand();
	void execute()override;
	void undo()override;
private:
	std::shared_ptr<ShapeLogic> m_logic;
	std::shared_ptr<ShapeVisual> m_visual;
	ShapeType m_type;
	IShapeCreator & m_creator;
};
