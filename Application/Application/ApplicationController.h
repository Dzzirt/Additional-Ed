#pragma once
#include "ApplicationModel.h"
#include "ApplicationView.h"
#include "SetShapePositionCommand.h"
#include "ShowShapeCommand.h"
#include "ShapeCreator.h"

class ApplicationController : public IShapeCreator
{
public:
	ApplicationController();
	ApplicationController(std::shared_ptr<ApplicationModel> model, std::shared_ptr<ApplicationView> view);
	~ApplicationController();
	void ProcessEvents(sf::Event & event);
	void UpdateOnButtonClick(const std::string & buttonName);

	size_t AddTriangle()override;
	size_t AddRectangle()override;
	size_t AddEllipse()override;

	void HideShape(size_t index)override;
	void UpdateOnShapeClick(size_t shapeIndex);
	void UpdateOnCanvasClick();
	void UpdateOnDrag(const sf::Vector2f & step);
	void UpdateOnDragRelease();
private:
	void DeleteInvisivbleShapes();
	void StabiliseIndexes();
	std::shared_ptr<ApplicationModel> m_model;
	std::shared_ptr<ApplicationView> m_view;
	boost::signals2::scoped_connection m_dragConnection;
	boost::signals2::scoped_connection m_releaseConnection;
	std::vector<boost::signals2::scoped_connection> m_buttonClickConnections;
	std::vector<boost::signals2::scoped_connection> m_shapeClickConnections;
	boost::signals2::connection m_canvasClickConnection;
};

