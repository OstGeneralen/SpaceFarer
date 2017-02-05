#pragma once
#include "GameEvents.h"

class Observer
{
public:
	virtual void Notify(GameEvent aEvent);
	virtual void Notify(GameEvent aEvent, int aValue);
	virtual void Notify(GameEvent aEvent, float aX, float aY);
};