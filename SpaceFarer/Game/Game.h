#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "..\Engine\DebugTools.h"
#include "..\Engine\Camera.h"

class Game
{
public:
	Game(bool& aShouldRun);
	void					Init();
	void					Update(float aDeltaTime);
	void					Render();
private:
	
	Camera					myDebugCamera;
	bool&					myShouldRun;
	Debug::DebugWidget*		myDebugTool;
	bool					myShouldShowDebugInfo;
	const sf::Color			myClearColor = sf::Color(0, 0, 0, 255);
	sf::RenderWindow		myGameWindow;
};