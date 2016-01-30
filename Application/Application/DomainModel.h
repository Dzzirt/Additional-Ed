#pragma once
#include "vector"
#include "ShapeLogic.h"
#include "Canvas.h"

class DomainModel
{
public:
	DomainModel();
	~DomainModel();
	void AddShapeLogic(std::shared_ptr<ShapeLogic> & shapeLogic);
	void RemoveShapeLogic(int pos);
	Canvas& GetCanvas();
	std::shared_ptr<ShapeLogic>& GetShape(int pos);
	std::vector<std::shared_ptr<ShapeLogic>>& GetShapes();
private:
	std::vector<std::shared_ptr<ShapeLogic>> m_shapesLogic;
	Canvas m_canvas;
	
};

