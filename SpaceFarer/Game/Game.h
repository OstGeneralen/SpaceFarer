#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "..\Game\Player.h"
#include "..\Engine\DebugTools.h"
#include "..\Engine\Camera.h"
#include <vector>
#include "..\Game\Asteroid.h"

class Game
{
public:
	Game(bool& aShouldRun);
	void Init();
	void Update(float aDeltaTime);
	void Render();
private:
	void HandleCollision(Actor& aActor1, Actor& aActor2);

	sf::RenderWindow myGameWindow;
	const sf::Color myClearColor = sf::Color(0, 0, 0, 255);
	Player myPlayer;
	Actor myTempActor;
	std::vector<Asteroid> myAsteroids;
	Actor myFrame;
	Debug::DebugWidget* myDebugTool;
	bool& myShouldRun;
	bool myShouldShowDebugInfo;
	Camera myGameCamera;
	Camera myGuiCamera;

	sf::Texture myPlayerTex;
	sf::Texture myAlienTex;
	sf::Texture myAsteroidTex;
	sf::Texture myFrameTex;
};