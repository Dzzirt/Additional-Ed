#include "ApplicationModel.h"


ApplicationModel::ApplicationModel(std::shared_ptr<DomainModel> domainModel)
	: m_domainModel(&*domainModel)
{
}


ApplicationModel::ApplicationModel() : m_domainModel(&DomainModel())
{

}

ApplicationModel::~ApplicationModel()
{
}

std::shared_ptr<ShapeLogic> ApplicationModel::CreateShape(ShapeType type)
{
	sf::Vector2f defaultPos = sf::Vector2f(m_domainModel->GetCanvas().GetPos() 
		+ m_domainModel->GetCanvas().GetSize() / 2.f - DefaultShapeSize / 2.f);
	sf::FloatRect & bounds = sf::FloatRect(defaultPos, DefaultShapeSize);
	auto & shape = std::make_shared<ShapeLogic>(bounds, type, m_domainModel->GetShapes().size());
	m_domainModel->AddShapeLogic(shape);
	return shape;
}

void ApplicationModel::RemoveShape(int pos)
{
	m_domainModel->RemoveShapeLogic(pos);
}

ShapeLogicVec & ApplicationModel::GetShapes()
{
	return m_domainModel->GetShapes();
}

void ApplicationModel::SetSize(int pos, sf::Vector2f const& size)
{
	m_domainModel->GetShape(pos)->SetSize(size);
}

void ApplicationModel::SetPosition(int pos, sf::Vector2f const& position)
{
	m_domainModel->GetShape(pos)->SetPosition(position);
}

void ApplicationModel::SetSelected(std::shared_ptr<ShapeLogic> & shapeLogic)
{
	shapeLogic->SetSelected(true);
	if (m_selectedShape)
	{
		m_selectedShape->SetSelected(false);
	}
	m_selectedShape = shapeLogic;
}

std::shared_ptr<ShapeLogic>& ApplicationModel::GetShape(size_t pos)
{
	return m_domainModel->GetShape(pos);
}

std::shared_ptr<ShapeLogic> & ApplicationModel::GetSelected()
{
	return m_selectedShape;
}

std::shared_ptr<ShapeLogic> & ApplicationModel::GetTempShape()
{
	return m_tempShape;
}

void ApplicationModel::AddCommand(std::shared_ptr<ICommand> & command)
{
	m_undoStack.push(command);
	while (!m_redoStack.empty())
	{
		m_redoStack.pop();
	}
}

void ApplicationModel::Undo()
{
	if (!m_undoStack.empty())
	{
		auto & cmd = m_undoStack.top();
		cmd->undo();
		m_redoStack.push(cmd);
		m_undoStack.pop();
	}
}

void ApplicationModel::Redo()
{
	if (!m_redoStack.empty())
	{
		auto & cmd = m_redoStack.top();
		cmd->execute();
		m_undoStack.push(cmd);
		m_redoStack.pop();
	}
}

