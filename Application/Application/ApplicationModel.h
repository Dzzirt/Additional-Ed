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
	void SetSelected(std::shared_ptr<ShapeLogic> & shapeLogic);
	std::shared_ptr<ShapeLogic>& GetShape(size_t pos);
	std::shared_ptr<ShapeLogic> & GetSelected();
private:
	DomainModel * m_domainModel;
	std::shared_ptr<ShapeLogic> m_selectedShape;
	boost::signals2::signal<void(sf::FloatRect)> onSelect;
};

