#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "..\Game\Player.h"
#include "..\Engine\DebugTools.h"
#include "..\Engine\Camera.h"
#include "..\Game\Asteroid.h"
#include <vector>
#include "Background.h"
#include "GUI\Gui.h"
#include "Ship.h"

class Game
{
public:
	Game(bool& aShouldRun);
	void					Init();
	void					Update(float aDeltaTime);
	void					Render();
private:
	void					HandleCollision(Actor& aActor1, Actor& aActor2);

	Background				myBackground;
	sf::RenderWindow		myGameWindow;
	const sf::Color			myClearColor = sf::Color(0, 0, 0, 255);
	Player					myPlayer;
	Actor					myTempActor;
	std::vector<Actor*>		myActors;
	Gui						myGui;
	Debug::DebugWidget*		myDebugTool;
	bool&					myShouldRun;
	bool					myShouldShowDebugInfo;
	Camera					myGameCamera;
	Camera					myGuiCamera;
	Ship					myTempShip;
};