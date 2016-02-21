#include "ApplicationController.h"
#include "iostream"

//Вынести команды в апп модель
//Избавиться от передачи указ. по ссылке
//для каждого угла свой алгоритм
ApplicationController::ApplicationController(std::shared_ptr<ApplicationModel> model, std::shared_ptr<ApplicationView> view)
	: m_model(model), m_view(view)
{
	Workspace & workspace = m_view->GetWorkspace();
	Frame & frame = m_view->GetFrame();
	m_dragConnection = frame.DoOnDrag(boost::bind(&ApplicationController::UpdateOnDrag, &*this, _1));
	m_releaseConnection = frame.DoOnRelease(boost::bind(&ApplicationController::UpdateOnDragRelease, &*this));
	m_resizeConnection = frame.DoOnResize(boost::bind(&ApplicationController::UpdateOnResize, &*this, _1, _2));
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
	 auto cmd = std::make_shared<AddShapeCommand>(*this, Rectangle);
	 cmd->execute();
	 m_model->AddCommand(cmd);
 }
 else if (buttonName == "Ellipse")
 {
	 auto cmd = std::make_shared<AddShapeCommand>(*this, Ellipse);
	 cmd->execute();
	 m_model->AddCommand(cmd);
 }
 else if (buttonName == "Triangle")
 {
	 auto cmd = std::make_shared<AddShapeCommand>(*this, Triangle);
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

void ApplicationController::AddShape(std::shared_ptr<ShapeLogic> & logic, std::shared_ptr<ShapeVisual>& visual, size_t index)
{
	auto clickConnectionIter = m_shapeClickConnections.begin() + index;
	auto clickConnection = visual->DoOnClick(boost::bind(&ApplicationController::UpdateOnShapeClick, &*this, _1));
	m_shapeClickConnections.insert(clickConnectionIter, clickConnection);
	m_view->GetWorkspace().AddShape(visual, index);
	m_model->AddShape(logic, index);
	visual->GetBoundsConnection() = logic->DoOnChange(boost::bind(&ShapeVisual::UpdateBounds, &*visual, _1));
}

void ApplicationController::AddShape(std::shared_ptr<ShapeLogic> & logic, std::shared_ptr<ShapeVisual>& visual)
{
	auto index = m_model->GetShapes().size();
	m_shapeClickConnections.push_back(visual->DoOnClick(boost::bind(&ApplicationController::UpdateOnShapeClick, &*this, _1)));
	visual->GetBoundsConnection() = logic->DoOnChange(boost::bind(&ShapeVisual::UpdateBounds, &*visual, _1));
	m_view->GetWorkspace().AddShape(visual, index);
	m_model->AddShape(logic, index);
}

size_t ApplicationController::DeleteShape(ShapeLogic & shapeLogic)
{
	auto index = m_model->GetShape(shapeLogic);
	auto & visualShapes = m_view->GetWorkspace().GetShapesVisual();
	auto & logicShapes = m_model->GetShapes();
	visualShapes.erase(visualShapes.begin() + index);
	logicShapes.erase(logicShapes.begin() + index);
	m_shapeClickConnections.erase(m_shapeClickConnections.begin() + index);
	return index;
}

void ApplicationController::UpdateOnShapeClick(const ShapeVisual & shapeVisual)
{
	m_model->SetSelected(m_model->GetShape(m_view->GetWorkspace().GetShapeIndex(shapeVisual)));
	m_view->GetFrame().GetBoundsConnection() = m_model->GetSelected()->DoOnChange(boost::bind(&Frame::UpdateBounds, &m_view->GetFrame(), _1));
}

void ApplicationController::UpdateOnCanvasClick()
{
//	m_model->GetSelected().reset();
//	m_view->GetFrame().SetVisible(false);
}

void ApplicationController::UpdateOnDrag(const sf::Vector2f & step)
{
	auto selected = m_model->GetSelected();
	auto & tempShape = m_model->GetTempShape();
	if (selected)
	{
		if (!tempShape)
		{
			size_t selectedIndex = m_model->GetShape(*selected);
			assert(selectedIndex != std::string::npos);
			tempShape = std::make_shared<ShapeLogic>(selected->GetBounds(), selected->GetType());
			auto & selectedVisual = m_view->GetWorkspace().GetShapesVisual().at(selectedIndex);
			tempShape->DoOnChange(boost::bind(&ShapeVisual::UpdateBounds, &*selectedVisual, _1));
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

void ApplicationController::UpdateOnResize(const sf::Vector2f & step, Corners corner)
{
	auto selectedIndex = m_model->GetShape(*m_model->GetSelected());
	auto & visualShapes = m_view->GetWorkspace().GetShapesVisual();
	if (corner == BottomLeft)
	{
		auto fixedStep = step;
		fixedStep.y = 0;
		m_model->GetSelected()->SetPosition(m_model->GetSelected()->GetPosition() + fixedStep);
		fixedStep = step;
		fixedStep.x *= -1.f;
		m_model->GetSelected()->SetSize(m_model->GetSelected()->GetSize() + fixedStep);

	}
	else if (corner == BottomRight)
	{
		m_model->GetSelected()->SetSize(m_model->GetSelected()->GetSize() + step);
	}
	else if (corner == UpperLeft)
	{
		m_model->GetSelected()->SetPosition(m_model->GetSelected()->GetPosition() + step);
		m_model->GetSelected()->SetSize(m_model->GetSelected()->GetSize() - step);
	}
	else if (corner == UpperRight)
	{
		auto fixedStep = step;
		fixedStep.x = 0;
		m_model->GetSelected()->SetPosition(m_model->GetSelected()->GetPosition() + fixedStep);
		fixedStep = step;
		fixedStep.y *= -1.f;
		m_model->GetSelected()->SetSize(m_model->GetSelected()->GetSize() + fixedStep);
	}
	m_model->GetSelected()->HandleChange();
}

ApplicationController::~ApplicationController()
{
}

