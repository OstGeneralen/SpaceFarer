#pragma once
#include "Observer.h"
#include <vector>

class Subject
{
public:
	virtual void AttatchObserver(Observer* aObserver);
	virtual void DetatchObserver(Observer* aObserver);
protected:
	void NotifyObservers(GameEvent aEvent);
	void NotifyObservers(GameEvent aEvent, int aValue);
	void NotifyObservers(GameEvent aEvent, float aX, float aY);
	void NotifyObservers(GameEvent aEvent, const sf::String& aString);
	std::vector<Observer*> myObservers;
};