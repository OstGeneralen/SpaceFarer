#include "State.h"

void State::Load(sf::RenderWindow * aGameWindow)
{
	myGameWindow = aGameWindow;
}

void State::Unload()
{
	myGameWindow = nullptr;
}

void State::WindowResize()
{
}

