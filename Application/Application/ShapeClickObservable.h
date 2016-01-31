#pragma once
#include "ShapeClickObserver.h"

class IShapeClickObservable
{
public:
	virtual void RegisterObserver(IShapeClickObserver & o) = 0;
	virtual void DeleteObserver(IShapeClickObserver & o) = 0;
	virtual void Notify() = 0;
};