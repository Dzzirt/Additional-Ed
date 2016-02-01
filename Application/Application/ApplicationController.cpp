#include "ApplicationController.h"
#include "iostream"
ApplicationController::ApplicationController(std::shared_ptr<ApplicationModel> model, std::shared_ptr<ApplicationView> view)
	: m_model(model), m_view(view)
{
	m_view->GetWorkspace().RegisterObserver(*this);
	auto & buttons = m_view->GetToolbar().GetButtons();
	for_each(buttons.begin(), buttons.end(), [&](std::shared_ptr<CButton> & button) 
	{
		button->RegisterObserver(*this);
	});
}

ApplicationController::ApplicationController()
{

}

void ApplicationController::ProcessEvents(sf::Event & event)
{

}

void ApplicationController::UpdateOnButtonClick(const std::string & buttonName)
{
 if (buttonName == "Rectangle")
 {
	 auto logicShape = m_model->CreateShape(Rectangle);
	 auto visualShape = std::make_shared<ShapeVisual>(std::make_shared<sf::RectangleShape>());
	 visualShape->RegisterObserver(*this);
	 logicShape->RegisterObserver(*visualShape);
	 m_view->GetWorkspace().AddShape(visualShape, m_view->GetWorkspace().GetShapesCount());
 }
 else if (buttonName == "Ellipse")
 {
	 auto logicShape = m_model->CreateShape(Ellipse);
	 auto visualShape = std::make_shared<ShapeVisual>(std::make_shared<EllipseShape>());
	 visualShape->RegisterObserver(*this);
	 logicShape->RegisterObserver(*visualShape);
	 m_view->GetWorkspace().AddShape(visualShape, m_view->GetWorkspace().GetShapesCount());
 }
 else if (buttonName == "Triangle")
 {
	 auto logicShape = m_model->CreateShape(Triangle);
	 auto visualShape = std::make_shared<ShapeVisual>(std::make_shared<sf::ConvexShape>());
	 visualShape->RegisterObserver(*this);
	 logicShape->RegisterObserver(*visualShape);
	 m_view->GetWorkspace().AddShape(visualShape, m_view->GetWorkspace().GetShapesCount());
 }
 else if (buttonName == "Undo")
 {

 }
 else if (buttonName == "Redo")
 {

 }
}

void ApplicationController::UpdateOnShapeClick(size_t shapeIndex)
{
	if (m_model->GetSelected())
	{
		m_model->GetSelected()->DeleteObserver(m_view->GetFrame());
	}
	m_model->SetSelected(m_model->GetShape(shapeIndex));
	m_model->GetSelected()->RegisterObserver(m_view->GetFrame());

}

void ApplicationController::UpdateOnCanvasClick()
{
	m_model->GetSelected().reset();
	m_view->GetFrame().SetVisible(false);
}

boost::signals2::connection& ApplicationController::GetButtonClickConnection()
{
	return m_buttonClickConnection;
}

boost::signals2::connection& ApplicationController::GetShapeClickConnection()
{
	return m_shapeClickConnection;
}

boost::signals2::connection& ApplicationController::GetCanvasClickConnection()
{
	return m_canvasClickConnection;
}

ApplicationController::~ApplicationController()
{
}

