#include "Game.h"
#include <iostream>
#include "..\Engine\DebugTools\FPSCounter.h"

Game::Game(bool& aShouldRun)
	: myShouldRun(aShouldRun)
{
	myShouldShowDebugInfo = false;
	myDebugTool = new D::FPSCounter(new D::Tools());
}

void Game::Init()
{
	myGameWindow.create(sf::VideoMode(800, 800), "SpaceFarer");
	myPlayer.Init("sprites/player.png", true);
}

void Game::Update(float aDeltaTime)
{
	sf::Event e;
	myGameWindow.pollEvent(e);

	if (e.type == sf::Event::Closed)
	{
		myGameWindow.close();
		myShouldRun = false;
	}

	if (e.type == sf::Event::KeyPressed)
	{
		if (e.key.code == sf::Keyboard::Key::D)
		{
			myShouldShowDebugInfo = !myShouldShowDebugInfo;
		}
	}

	if (myShouldShowDebugInfo)
	{
		myDebugTool->Update(aDeltaTime);
	}

	myPlayer.Update(aDeltaTime);
}

void Game::Render()
{
	myGameWindow.clear(myClearColor);

	//Todo: Add Render code here
	myPlayer.Render(myGameWindow);

	if (myShouldShowDebugInfo)
	{
		myDebugTool->Render(myGameWindow);
	}

	myGameWindow.display();

}
