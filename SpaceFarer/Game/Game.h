#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "GUI\Cursor.h"
#include "..\Engine\DebugTools.h"
#include "..\Engine\Camera.h"
#include "..\Engine\json.hpp"


class Game
{
public:
	Game(bool& aShouldRun);
	void					Init();
	void					Update(float aDeltaTime);
	void					Render();
private:
	jsonWrapper::json		myMasterJson;
	Cursor					myCursor;
	Camera					myDebugCamera;
	bool&					myShouldRun;
	Debug::DebugWidget*		myDebugTool;
	bool					myShouldShowDebugInfo;
	const sf::Color			myClearColor = sf::Color(0, 0, 0, 255);
	sf::RenderWindow		myGameWindow;
};