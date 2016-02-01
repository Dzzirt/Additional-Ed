#pragma once
#include "CanvasClickObserver.h"

class ICanvasClickObservable
{
public:
	virtual void RegisterObserver(ICanvasClickObserver & o) = 0;
	virtual void DeleteObserver(ICanvasClickObserver & o) = 0;
	virtual void Notify() = 0;
};