#pragma once
#include <memory>
#include "Shape.h"
#include "vector"

class IShapeCreator
{
public:
	virtual std::shared_ptr<IShape> CreateShape(std::vector<std::string> const& shapeInfo) = 0;
	virtual ~IShapeCreator() = default;
};