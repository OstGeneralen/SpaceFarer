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
	bool&					myShouldRun;
	bool					myShouldShowDebugInfo;
	Cursor					myCursor;
	Debug::DebugWidget*		myDebugTool;
	Camera					myDebugCamera;
	sf::RenderWindow		myGameWindow;
	const sf::Color			myClearColor = sf::Color(0, 0, 0, 255);
};