#include "ApplicationController.h"

ApplicationController::ApplicationController(std::shared_ptr<ApplicationModel> model, std::shared_ptr<ApplicationView> view)
	: m_model(model), m_view(view)
{
	auto & buttons = m_view->GetToolbar().GetButtons();
	for_each(buttons.begin(), buttons.end(), [&](std::shared_ptr<CButton> & button)
	{
		button->onClick.connect(boost::bind(&ApplicationController::OnButtonClick, &*this, _1));
	});
}

ApplicationController::ApplicationController()
{

}

void ApplicationController::ProcessEvents(sf::Event & event)
{

}

void ApplicationController::OnButtonClick(const std::string & buttonName)
{
 if (buttonName == "Rectangle")
 {
	 auto logicShape = m_model->CreateShape(Rectangle);
	 auto visualShape = std::make_shared<ShapeVisual>(std::make_shared<sf::RectangleShape>());
	 logicShape->m_onChange.connect(boost::bind(&ShapeVisual::Update, &*visualShape, _1, _2));
	 m_view->GetWorkspace().AddShape(visualShape);
	 logicShape->m_onChange(logicShape->GetPosition(), logicShape->GetSize());
 }
 else if (buttonName == "Ellipse")
 {
	 auto logicShape = m_model->CreateShape(Ellipse);
	 auto visualShape = std::make_shared<ShapeVisual>(std::make_shared<EllipseShape>());
	 logicShape->m_onChange.connect(boost::bind(&ShapeVisual::Update, &*visualShape, _1, _2));
	 m_view->GetWorkspace().AddShape(visualShape);
 }
 else if (buttonName == "Triangle")
 {
	 auto logicShape = m_model->CreateShape(Triangle);
	 auto visualShape = std::make_shared<ShapeVisual>(std::make_shared<sf::CircleShape>());
	 logicShape->m_onChange.connect(boost::bind(&ShapeVisual::Update, &*visualShape, _1, _2));
	 m_view->GetWorkspace().AddShape(visualShape);
 }
 else if (buttonName == "Undo")
 {

 }
 else if (buttonName == "Redo")
 {

 }
}

ApplicationController::~ApplicationController()
{
}

