#pragma once
#include "ShapeLogic.h"
#include "ShapeVisual.h"

class IShapeCreator
{
public:
	virtual void AddShape(std::shared_ptr<ShapeLogic> & logic, std::shared_ptr<ShapeVisual>& visual, size_t index) = 0;
	virtual void AddShape(std::shared_ptr<ShapeLogic> & logic, std::shared_ptr<ShapeVisual>& visual) = 0;
	virtual size_t DeleteShape(ShapeLogic & shapeLogic) = 0;
};
