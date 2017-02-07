#include "State.h"

void State::Load(sf::RenderWindow * aGameWindow)
{
	myGameWindow = aGameWindow;
	myIsLoaded = true;
}

void State::WindowResize()
{
}

bool State::GetIsLoaded() const
{
	return myIsLoaded;
}
