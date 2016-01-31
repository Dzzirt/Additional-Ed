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
	//shape->SetPosition(sf::Vector2f(m_canvasVisual.getPosition().x + rand() % 300, m_canvasVisual.getPosition().y + rand() % 300));
	sf::Vector2f defaultPos = sf::Vector2f(m_domainModel->GetCanvas().GetPos() 
		+ sf::Vector2f(rand() % 300, rand() % 300));
	auto & shape = std::make_shared<ShapeLogic>(defaultPos, DefaultShapeSize, type);
	m_domainModel->AddShapeLogic(shape);
	return shape;
}

void ApplicationModel::RemoveShape(int pos)
{
	m_domainModel->RemoveShapeLogic(pos);
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

