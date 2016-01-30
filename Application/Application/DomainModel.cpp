#include "DomainModel.h"
#include "AppConsts.h"

DomainModel::DomainModel()
{
	float border = (WindowWidth - CanvasSize.x) / 2.f;
	sf::Vector2f canvasPos(border, WindowHeight - CanvasSize.y - border);
	m_canvas = Canvas(canvasPos, CanvasSize);
}


DomainModel::~DomainModel()
{
}

void DomainModel::AddShapeLogic(std::shared_ptr<ShapeLogic> & shapeLogic)
{
	m_shapesLogic.push_back(shapeLogic);
}

void DomainModel::RemoveShapeLogic(int pos)
{
	m_shapesLogic.erase(m_shapesLogic.begin() + pos);
}

Canvas& DomainModel::GetCanvas()
{
	return m_canvas;
}

std::shared_ptr<ShapeLogic>& DomainModel::GetShape(int pos)
{
	return m_shapesLogic.at(pos);
}

std::vector<std::shared_ptr<ShapeLogic>>& DomainModel::GetShapes()
{
	return m_shapesLogic;
}
