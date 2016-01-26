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
	ApplicationView(const SAssets & assets);
	ApplicationView();
	~ApplicationView();
	void Draw(sf::RenderWindow & window);
	void ProcessVisualEvents(const sf::Event & event);
	Toolbar & GetToolbar();
	Workspace & GetWorkspace();
private:
	Toolbar toolbar;
	Workspace workspace;
};


