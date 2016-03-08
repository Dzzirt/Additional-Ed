#include "DomainModel.h"
#include "AppConsts.h"
#include <stdexcept>

DomainModel::DomainModel()
{
	float border = (WindowWidth - CanvasSize.x) / 2.f;
	sf::Vector2f canvasPos(border, WindowHeight - CanvasSize.y - border);
}


DomainModel::~DomainModel()
{
}

void DomainModel::AddShapeLogic(std::shared_ptr<ShapeLogic> & shapeLogic, size_t index)
{
	m_shapesLogic.insert(m_shapesLogic.begin() + index, shapeLogic);
}

void DomainModel::RemoveShapeLogic(int pos)
{
	m_shapesLogic.erase(m_shapesLogic.begin() + pos);
}

std::shared_ptr<ShapeLogic>& DomainModel::GetShape(size_t pos)
{
	return m_shapesLogic.at(pos);
}

std::vector<std::shared_ptr<ShapeLogic>>& DomainModel::GetShapes()
{
	return m_shapesLogic;
}

size_t DomainModel::GetShapeIndex(ShapeLogic & shapeLogic)
{
	auto it = std::find_if(m_shapesLogic.begin(), m_shapesLogic.end(), [&](std::shared_ptr<ShapeLogic> & m_shapeLogic) {
		return &*m_shapeLogic == &shapeLogic;
	});
	assert(it <= m_shapesLogic.end());
	return it - m_shapesLogic.begin();
}
