#pragma once
#include "Shape.h"
#include <vector>
#include <map>
#include <memory>
#include <iostream>
#include <functional>
#include "ShapeCreator.h"

typedef std::function<std::shared_ptr<IShape>(std::vector<std::string> const& params)> ShapeCreator;

class CShapeManager : public IShapeCreator
{
public:
	

	CShapeManager() = delete;
	CShapeManager(std::istream & is);
	void Render();
	void Print();
	std::shared_ptr<IShape> CreateShape(std::vector<std::string> const& shapeInfo) override;

	std::shared_ptr<IShape> CreateCircle(std::vector<std::string> const& shapeInfo);

	std::shared_ptr<IShape> CreateTriangle(std::vector<std::string> const& shapeInfo);

	std::shared_ptr<IShape> CreateLine(std::vector<std::string> const& shapeInfo);

	std::shared_ptr<IShape> CreateRectangle(std::vector<std::string> const& shapeInfo);
private:
	void LoadShapes();
	void LoadShapeCreators();
	std::istream & m_input;
	std::vector<std::shared_ptr<IShape>> m_shapes;
	std::map<std::string, ShapeCreator> m_shapeCreators;
};

