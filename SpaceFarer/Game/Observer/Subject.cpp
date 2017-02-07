#include "Subject.h"

void Subject::AttatchObserver(Observer * aObserver)
{
	myObservers.push_back(aObserver);
}

void Subject::DetatchObserver(Observer * aObserver)
{
	for (unsigned int index = 0; index < myObservers.size(); ++index)
	{
		if (myObservers[index] == aObserver)
		{
			myObservers.erase(myObservers.begin() + index);
			break;
		}
	}
}

void Subject::NotifyObservers(GameEvent aEvent)
{
	for (unsigned int index = 0; index < myObservers.size(); ++index)
	{
		myObservers[index]->Notify(aEvent);
	}
}

void Subject::NotifyObservers(GameEvent aEvent, int aValue)
{
	for (unsigned int index = 0; index < myObservers.size(); ++index)
	{
		myObservers[index]->Notify(aEvent, aValue);
	}
}

void Subject::NotifyObservers(GameEvent aEvent, float aX, float aY)
{
	for (unsigned int index = 0; index < myObservers.size(); ++index)
	{
		myObservers[index]->Notify(aEvent, aX, aY);
	}
}

void Subject::NotifyObservers(GameEvent aEvent, const sf::String& aString)
{
	for (unsigned int index = 0; index < myObservers.size(); ++index)
	{
		myObservers[index]->Notify(aEvent, aString);
	}
}
