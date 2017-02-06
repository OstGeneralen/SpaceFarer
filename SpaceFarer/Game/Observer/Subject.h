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
	std::vector<Observer*> myObservers;
};