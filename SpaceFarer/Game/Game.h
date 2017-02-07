#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "..\Engine\DebugTools.h"
#include "States\FlyingState.h"
#include "..\Engine\Camera.h"

enum class GameState
{
	Flying,
};

class Game
{
public:
	Game(bool& aShouldRun);
	void					Init();
	void					Update(float aDeltaTime);
	void					Render();
private:

	GameState				myGameState;

	FlyingState				myFlyingState;
	Camera					myDebugCamera;
	bool&					myShouldRun;
	Debug::DebugWidget*		myDebugTool;
	bool					myShouldShowDebugInfo;
	const sf::Color			myClearColor = sf::Color(0, 0, 0, 255);
	sf::RenderWindow		myGameWindow;
};