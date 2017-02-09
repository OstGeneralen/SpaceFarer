#include "State.h"

void State::Load(sf::RenderWindow * aGameWindow)
{
	myGameWindow = aGameWindow;
}

void State::LoadWithPosition(const sf::Vector2f& aPosition)
{
	myLoadedPosition = aPosition;
}

void State::Unload()
{
	myGameWindow = nullptr;
}

void State::WindowResize()
{
}

