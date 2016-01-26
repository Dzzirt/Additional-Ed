#pragma once
#include "Command.h"
#include "WorkSpace.h"

class AddEllipseCommand : public Command
{
public:
	AddEllipseCommand(Workspace & workspace);
	~AddEllipseCommand();
	void execute();
	void undo();

private:
	Workspace & m_workspace;
};
