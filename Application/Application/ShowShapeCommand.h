#pragma once
#include "Command.h"
#include "ApplicationView.h"
#include "AppConsts.h"

class ShowShapeCommand : public ICommand
{
public:
	ShowShapeCommand(ApplicationView & view, size_t index);
	~ShowShapeCommand();
	void execute()override;
	void undo()override;
private:
	ApplicationView & m_view;
	size_t m_index;
};
