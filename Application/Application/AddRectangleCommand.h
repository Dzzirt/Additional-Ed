#pragma once
#include "Command.h"
#include "WorkSpace.h"

class AddRectangleCommand : public Command
{
public:
	AddRectangleCommand(Workspace & workspace);
	~AddRectangleCommand();
	void execute();
	void undo();

private:
	Workspace & m_workspace;
};

