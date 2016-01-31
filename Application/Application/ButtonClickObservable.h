#pragma once
#include "ButtonClickObserver.h"

class IButtonClickObservable
{
public:
	virtual void RegisterObserver(IButtonClickObserver & o) = 0;
	virtual void DeleteObserver(IButtonClickObserver & o) = 0;
	virtual void Notify() = 0;
};