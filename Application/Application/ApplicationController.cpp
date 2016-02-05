#include "ApplicationController.h"
#include "iostream"

ApplicationController::ApplicationController(std::shared_ptr<ApplicationModel> model, std::shared_ptr<ApplicationView> view)
	: m_model(model), m_view(view)
{
	Workspace & workspace = m_view->GetWorkspace();
	Frame & frame = m_view->GetFrame();
	m_dragConnection = frame.DoOnDrag(boost::bind(&ApplicationController::UpdateOnDrag, &*this, _1));
	m_releaseConnection = frame.DoOnRelease(boost::bind(&ApplicationController::UpdateOnDragRelease, &*this));
	m_canvasClickConnection = workspace.DoOnClick(boost::bind(&ApplicationController::UpdateOnCanvasClick, &*this));
	auto & buttons = m_view->GetToolbar().GetButtons();
	for_each(buttons.begin(), buttons.end(), [&](std::shared_ptr<CButton> & button) 
	{
		m_buttonClickConnections.push_back(button->DoOnClick(boost::bind(&ApplicationController::UpdateOnButtonClick, &*this, _1)));
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
	 DeleteInvisivbleShapes();
	 auto index = AddRectangle();
	 std::shared_ptr<ICommand> cmd = std::make_shared<ShowShapeCommand>(*m_view, index);
	 cmd->execute();
	 m_model->AddCommand(cmd);

 }
 else if (buttonName == "Ellipse")
 {
	 DeleteInvisivbleShapes();
	 auto index = AddEllipse();
	 std::shared_ptr<ICommand> cmd = std::make_shared<ShowShapeCommand>(*m_view, index);
	 cmd->execute();
	 m_model->AddCommand(cmd);

 }
 else if (buttonName == "Triangle")
 {
	 DeleteInvisivbleShapes();
	 auto index = AddTriangle();
	 std::shared_ptr<ICommand> cmd = std::make_shared<ShowShapeCommand>(*m_view, index);
	 cmd->execute();
	 m_model->AddCommand(cmd);
 }
 else if (buttonName == "Undo")
 {
	 m_model->Undo();
	 m_view->GetFrame().SetVisible(false);
 }
 else if (buttonName == "Redo")
 {
	 m_model->Redo();
	 m_view->GetFrame().SetVisible(false);
 }
 
}

size_t ApplicationController::AddTriangle()
{
	auto logicShape = m_model->CreateShape(Triangle);
	auto visualShape = std::make_shared<ShapeVisual>(std::make_shared<sf::ConvexShape>());
	m_shapeClickConnections.push_back(visualShape->DoOnClick(boost::bind(&ApplicationController::UpdateOnShapeClick, &*this, _1)));
	visualShape->GetBoundsConnection() = logicShape->DoOnChange(boost::bind(&ShapeVisual::UpdateBounds, &*visualShape, _1, _2));
	m_view->GetWorkspace().AddShape(visualShape, m_view->GetWorkspace().GetShapesCount());
	return logicShape->GetIndex();
}

size_t ApplicationController::AddRectangle()
{
	auto logicShape = m_model->CreateShape(Rectangle);
	auto visualShape = std::make_shared<ShapeVisual>(std::make_shared<sf::RectangleShape>());
	m_shapeClickConnections.push_back(visualShape->DoOnClick(boost::bind(&ApplicationController::UpdateOnShapeClick, &*this, _1)));
	visualShape->GetBoundsConnection() = logicShape->DoOnChange(boost::bind(&ShapeVisual::UpdateBounds, &*visualShape, _1, _2));
	m_view->GetWorkspace().AddShape(visualShape, m_view->GetWorkspace().GetShapesCount());
	return logicShape->GetIndex();
}

size_t ApplicationController::AddEllipse()
{
	auto logicShape = m_model->CreateShape(Ellipse);
	auto visualShape = std::make_shared<ShapeVisual>(std::make_shared<EllipseShape>());
	m_shapeClickConnections.push_back(visualShape->DoOnClick(boost::bind(&ApplicationController::UpdateOnShapeClick, &*this, _1)));
	visualShape->GetBoundsConnection() = logicShape->DoOnChange(boost::bind(&ShapeVisual::UpdateBounds, &*visualShape, _1, _2));
	m_view->GetWorkspace().AddShape(visualShape, m_view->GetWorkspace().GetShapesCount());
	return logicShape->GetIndex();
}

void ApplicationController::DeleteInvisivbleShapes()
{
	auto & visualShapes = m_view->GetWorkspace().GetShapesVisual();
	auto & logicShapes = m_model->GetShapes();

	for (size_t i = 0; i < logicShapes.size(); i++)
	{
		if (!visualShapes.at(i)->GetVisible())
		{

		}
	}
}

void ApplicationController::HideShape(size_t index)
{
	m_view->GetWorkspace().GetShapesVisual().at(index)->SetVisible(false);
	m_view->GetFrame().SetVisible(false);
}

void ApplicationController::UpdateOnShapeClick(size_t shapeIndex)
{
	if (m_model->GetSelected())
	{
		m_view->GetFrame().GetBoundsConnection().disconnect();
	}
	m_model->SetSelected(m_model->GetShape(shapeIndex));
	m_view->GetFrame().GetBoundsConnection() = m_model->GetSelected()->DoOnChange(boost::bind(&Frame::UpdateBounds, &m_view->GetFrame(), _1));

}

void ApplicationController::UpdateOnCanvasClick()
{
	m_view->GetFrame().SetVisible(false);
}

void ApplicationController::UpdateOnDrag(const sf::Vector2f & step)
{
	auto selected = m_model->GetSelected();
	auto & tempShape = m_model->GetTempShape();
	if (selected)
	{
		if (!tempShape)
		{
			tempShape = std::make_shared<ShapeLogic>(selected->GetBounds(), selected->GetType(), selected->GetIndex());
			auto & selectedVisual = m_view->GetWorkspace().GetShapesVisual().at(selected->GetIndex());
			tempShape->DoOnChange(boost::bind(&ShapeVisual::UpdateBounds, &*selectedVisual, _1, _2));
			tempShape->DoOnChange(boost::bind(&Frame::UpdateBounds, &m_view->GetFrame(), _1));
		}
		tempShape->SetPosition(tempShape->GetPosition() + step);
		
	}
}

void ApplicationController::UpdateOnDragRelease()
{
	auto selected = m_model->GetSelected();
	auto & tempShape = m_model->GetTempShape();
	if (selected)
	{
		if (tempShape)
		{
			std::shared_ptr<ICommand> setPos = std::make_shared<SetShapePositionCommand>(*selected, tempShape->GetPosition());
			setPos->execute();
			m_model->AddCommand(setPos);
			tempShape.reset();
		}

	}
}

ApplicationController::~ApplicationController()
{
}

