#pragma once
#include "BoundsObserver.h"

class IBoundsObservable
{
public:
	virtual void RegisterObserver(IBoundsObserver & o) = 0;
	virtual void DeleteObserver(IBoundsObserver & o) = 0;
	virtual void Notify() = 0;
};