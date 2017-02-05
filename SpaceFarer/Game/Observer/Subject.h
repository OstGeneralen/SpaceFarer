#pragma once
#include "Observer.h"
#include <vector>

class Subject
{
public:
	void AttatchObserver(Observer* aObserver);
	void DetatchObserver(Observer* aObserver);
protected:
	void NotifyObservers(GameEvent aEvent);
	void NotifyObservers(GameEvent aEvent, int aValue);
	void NotifyObservers(GameEvent aEvent, float aX, float aY);
	std::vector<Observer*> myObservers;
};