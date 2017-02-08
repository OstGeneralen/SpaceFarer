#pragma once
#include "SFML\Graphics\RenderWindow.hpp"

class State
{
public:
	virtual void Load(sf::RenderWindow* aGameWindow);
	virtual void Update(float aDeltaTime) = 0;
	virtual void Render() = 0;
	virtual void WindowResize();
	bool GetIsLoaded() const;
protected:
	sf::RenderWindow* myGameWindow = nullptr;
	bool myIsLoaded = false;
};