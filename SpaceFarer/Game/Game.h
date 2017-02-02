#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "..\Game\Player.h"
#include "..\Engine\DebugTools.h"
#include "..\Engine\Camera.h"

class Game
{
public:
	Game(bool& aShouldRun);
	void Init();
	void Update(float aDeltaTime);
	void Render();
private:
	sf::RenderWindow myGameWindow;
	const sf::Color myClearColor = sf::Color(0, 150, 255, 255);
	Player myPlayer;
	Actor myTempActor;
	Actor myFrame;
	Debug::DebugWidget* myDebugTool;
	bool& myShouldRun;
	bool myShouldShowDebugInfo;
	Camera myGameCamera;
	Camera myGuiCamera;
};