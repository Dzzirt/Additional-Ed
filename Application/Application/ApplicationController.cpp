#include "ApplicationController.h"

ApplicationController::ApplicationController(ApplicationView & view)
	: m_view(view), undoCounter(0)
{
	m_view.GetToolbar().GetButton("Rectangle").handler = [&]()
	{
		if (undoCounter > 0)
		{
			commandsHistory = std::vector<std::shared_ptr<Command>>(commandsHistory.begin(), commandsHistory.end() - undoCounter);
			undoCounter = 0;
		}
		command = std::make_shared<AddRectangleCommand>(m_view.GetWorkspace());
		commandsHistory.push_back(command);
		command->execute();
	};
	m_view.GetToolbar().GetButton("Triangle").handler = [&]()
	{
		if (undoCounter > 0)
		{
			commandsHistory = std::vector<std::shared_ptr<Command>>(commandsHistory.begin(), commandsHistory.end() - undoCounter);
			undoCounter = 0;
		}
		command = std::make_shared<AddTriangleCommand>(m_view.GetWorkspace());
		commandsHistory.push_back(command);
		command->execute();
	};
	m_view.GetToolbar().GetButton("Ellipse").handler = [&]()
	{
		if (undoCounter > 0)
		{
			commandsHistory = std::vector<std::shared_ptr<Command>>(commandsHistory.begin(), commandsHistory.end() - undoCounter);
			undoCounter = 0;
		}
		command = std::make_shared<AddEllipseCommand>(m_view.GetWorkspace());
		commandsHistory.push_back(command);
		command->execute();
	};
	m_view.GetToolbar().GetButton("Undo").handler = [&]()
	{
		if (command)
		{
			command->undo();
			if (commandsHistory.size() > undoCounter)
			{
				undoCounter++;
				command = commandsHistory.at(commandsHistory.size() - undoCounter);
			}
		}
	};
	m_view.GetToolbar().GetButton("Redo").handler = [&]()
	{
		if (undoCounter > 0)
		{
			command = commandsHistory.at(commandsHistory.size() - undoCounter);
			command->execute();
			undoCounter--;
		}
	};
}

ApplicationController::~ApplicationController()
{
}