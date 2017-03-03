#pragma once
#include "SFML\Graphics\RenderWindow.hpp"
#include "..\GameData.h"

class State
{
public:
	virtual void		Load(GameData aData);
	virtual void		Unload();
	virtual void		Update(float aDeltaTime) = 0;
	virtual void		Render() = 0;
	virtual void		WindowResize();
protected:
	GameData			myData;
	sf::Vector2f		myLoadedPosition;
};