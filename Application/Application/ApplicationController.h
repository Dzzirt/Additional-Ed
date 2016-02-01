#pragma once
#include "ApplicationModel.h"
#include "ApplicationView.h"

class ApplicationController 
	: public IButtonClickObserver, public IShapeClickObserver, public ICanvasClickObserver
{
public:
	ApplicationController();
	ApplicationController(std::shared_ptr<ApplicationModel> model, std::shared_ptr<ApplicationView> view);
	~ApplicationController();
	void ProcessEvents(sf::Event & event);
	void UpdateOnButtonClick(const std::string & buttonName)override;
	void UpdateOnShapeClick(size_t shapeIndex)override;
	void UpdateOnCanvasClick()override;
	boost::signals2::connection& GetButtonClickConnection()override;
	boost::signals2::connection& GetShapeClickConnection()override;
	boost::signals2::connection& GetCanvasClickConnection()override;
private:
	std::shared_ptr<ApplicationModel> m_model;
	std::shared_ptr<ApplicationView> m_view;
	boost::signals2::connection m_buttonClickConnection;
	boost::signals2::connection m_shapeClickConnection;
	boost::signals2::connection m_canvasClickConnection;
};

