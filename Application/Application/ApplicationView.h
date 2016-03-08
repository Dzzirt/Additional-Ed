#pragma once
#include "TextButton.h"
#include "ImageButton.h"
#include "Toolbar.h"
#include "assets.h"
#include "AppConsts.h"
#include "WorkSpace.h"


class ApplicationView
{
public:
	ApplicationView();
	~ApplicationView();
	void Draw(sf::RenderWindow & window);
	void ProcessVisualEvents(const sf::Event & event, sf::RenderWindow & window);
	Toolbar & GetToolbar();
	Workspace & GetWorkspace();
	Frame & GetFrame();

private:
	Toolbar m_toolbar;
	std::shared_ptr<Workspace> m_workspace;
	Frame m_frame;

};


