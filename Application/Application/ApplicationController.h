#pragma once
#include "ApplicationModel.h"
#include "ApplicationView.h"

class ApplicationController
{
public:
	ApplicationController();
	ApplicationController(std::shared_ptr<ApplicationModel> model, std::shared_ptr<ApplicationView> view);
	~ApplicationController();
	void ProcessEvents(sf::Event & event);
	void OnButtonClick(const std::string & buttonName);
private:
	std::shared_ptr<ApplicationModel> m_model;
	std::shared_ptr<ApplicationView> m_view;
};

