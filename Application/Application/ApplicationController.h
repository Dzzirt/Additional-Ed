#pragma once
#include "ApplicationView.h"
#include "AddRectangleCommand.h"
#include "AddTriangleCommand.h"
#include "AddEllipseCommand.h"

class ApplicationController
{
public:
	ApplicationController(ApplicationView & view);
	~ApplicationController();

private:
	ApplicationView & m_view;
	std::shared_ptr<Command> command;
	std::vector<std::shared_ptr<Command>> commandsHistory;
	unsigned undoCounter;
};

