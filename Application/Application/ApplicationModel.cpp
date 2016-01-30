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
		+ m_domainModel->GetCanvas().GetSize() / 2.f);
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
