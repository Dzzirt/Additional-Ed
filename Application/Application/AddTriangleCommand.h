#pragma once
#include "Command.h"
#include "WorkSpace.h"

class AddTriangleCommand : public Command
{
public:
	AddTriangleCommand(Workspace & workspace);
	~AddTriangleCommand();
	void execute();
	void undo();

private:
	Workspace & m_workspace;
};
