#pragma once
#include "SFML\Graphics\RenderWindow.hpp"

class State
{
public:
	virtual void		Load(sf::RenderWindow* aGameWindow);
	virtual void		LoadWithPosition(const sf::Vector2f& aPosition);
	virtual void		Unload();
	virtual void		Update(float aDeltaTime) = 0;
	virtual void		Render() = 0;
	virtual void		WindowResize();
protected:
	sf::RenderWindow*	myGameWindow = nullptr;
	sf::Vector2f		myLoadedPosition;
};