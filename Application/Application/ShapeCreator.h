#pragma once

class IShapeCreator
{
public:
	virtual size_t AddTriangle() = 0;
	virtual size_t AddRectangle() = 0;
	virtual size_t AddEllipse() = 0;
	virtual void HideShape(size_t index) = 0;
};
