#pragma once
#include "vector"
#include "ShapeLogic.h"
#include "IShapeOwner.h"

class DomainModel : public IShapeOwner
{
public:
	DomainModel();
	~DomainModel();
	void AddShapeLogic(std::shared_ptr<ShapeLogic> & shapeLogic, size_t index);
	void RemoveShapeLogic(int pos);
	std::shared_ptr<ShapeLogic>& GetShape(size_t pos);
	std::vector<std::shared_ptr<ShapeLogic>>& GetShapes();
	size_t GetShapeIndex(ShapeLogic & shapeLogic);
private:
	std::vector<std::shared_ptr<ShapeLogic>> m_shapesLogic;
};

