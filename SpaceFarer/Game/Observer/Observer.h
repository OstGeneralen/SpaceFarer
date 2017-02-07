#pragma once
#include "GameEvents.h"

namespace sf
{
	class String;
}

class Observer
{
public:
	virtual void Notify(GameEvent aEvent);
	virtual void Notify(GameEvent aEvent, int aValue);
	virtual void Notify(GameEvent aEvent, float aX, float aY);
	virtual void Notify(GameEvent aEvent, const sf::String& aString);
};