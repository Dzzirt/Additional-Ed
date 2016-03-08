#pragma once
#include "ApplicationModel.h"
#include "ApplicationView.h"
#include "SetShapePositionCommand.h"
#include "AddShapeCommand.h"
#include "DeleteShapeCommand.h"
#include "ShapeCreator.h"

class ApplicationController : public IShapeCreator
{
public:
	ApplicationController();
	ApplicationController(std::shared_ptr<ApplicationModel> model, std::shared_ptr<ApplicationView> view);
	~ApplicationController();
	void ProcessEvents(sf::Event & event);
	void UpdateOnButtonClick(const std::string & buttonName);

	void AddShape(std::shared_ptr<ShapeLogic> & logic, std::shared_ptr<ShapeVisual>& visual, size_t index)override;
	void AddShape(std::shared_ptr<ShapeLogic> & logic, std::shared_ptr<ShapeVisual>& visual)override;
	size_t DeleteShape(ShapeLogic & shapeLogic)override;

	void UpdateOnShapeClick(const ShapeVisual & shapeVisual);
	void UpdateOnCanvasClick();
	void UpdateOnDrag(const sf::Vector2f & step);
	void UpdateOnDragRelease();
	void UpdateOnResize(const sf::Vector2f & step, Corners corner);
private:

	std::shared_ptr<ApplicationModel> m_model;
	std::shared_ptr<ApplicationView> m_view;
	boost::signals2::scoped_connection m_dragConnection;
	boost::signals2::scoped_connection m_releaseConnection;
	boost::signals2::scoped_connection m_resizeConnection;
	std::vector<boost::signals2::scoped_connection> m_buttonClickConnections;
	std::vector<boost::signals2::scoped_connection> m_shapeClickConnections;
	boost::signals2::connection m_canvasClickConnection;
};

