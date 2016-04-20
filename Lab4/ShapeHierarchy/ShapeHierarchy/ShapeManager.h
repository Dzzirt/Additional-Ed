#pragma once
#include "Shape.h"
#include <vector>
#include <memory>
#include <iostream>
#include "ShapeCreator.h"

class CShapeManager : public IShapeCreator
{
public:
	CShapeManager() = delete;
	CShapeManager(std::istream & is);
	void Render();
	void Print();
	std::shared_ptr<IShape> CreateShape(std::vector<std::string> const& shapeInfo) override;
private:
	void LoadShapes();
	std::istream & m_input;
	std::vector<std::shared_ptr<IShape>> m_shapes;
};

