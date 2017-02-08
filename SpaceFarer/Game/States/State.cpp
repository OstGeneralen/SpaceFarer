#include "State.h"

void State::Load(sf::RenderTexture * aGameWindow)
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
