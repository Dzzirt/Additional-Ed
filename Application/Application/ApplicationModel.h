#pragma once
#include "DomainModel.h"

class ApplicationModel
{
public:
	ApplicationModel();
	ApplicationModel(std::shared_ptr<DomainModel> domainModel);
	~ApplicationModel();
	std::shared_ptr<ShapeLogic> CreateShape(ShapeType type);
	void RemoveShape(int pos);
	void SetSize(int pos, sf::Vector2f const& size);
	void SetPosition(int pos, sf::Vector2f const& position);

private:
	DomainModel * m_domainModel;
};

