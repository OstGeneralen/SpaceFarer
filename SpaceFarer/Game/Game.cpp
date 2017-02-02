#include "Game.h"
#include <iostream>
#include "..\Engine\DebugTools\FPSCounter.h"

Game::Game(bool& aShouldRun)
	: myShouldRun(aShouldRun)
{
#ifdef _DEBUG
	myShouldShowDebugInfo = true;
#else
	myShouldShowDebugInfo = false;
#endif

	myDebugTool = new D::FPSCounter(new D::Tools());
}

void Game::Init()
{
	myGameWindow.create(sf::VideoMode::getDesktopMode(), "SpaceFarer");
	myPlayer.Init("sprites/player.png", true);
	myTempActor.Init("sprites/Trash/alien.png", true, { 20,20 });
	myFrame.Init("sprites/frame.png");
	myGameCamera.SetTarget(&myPlayer);
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
		if (e.key.code == sf::Keyboard::Key::A)
		{
			myGameCamera.SetTarget(&myTempActor);
		}
		if (e.key.code == sf::Keyboard::Key::P)
		{
			myGameCamera.SetTarget(&myPlayer);
		}
	}

	if (e.type == sf::Event::Resized)
	{
		myGameCamera.Resize(static_cast<float>(myGameWindow.getSize().x), static_cast<float>(myGameWindow.getSize().y));
		myGuiCamera.Resize(static_cast<float>(myGameWindow.getSize().x), static_cast<float>(myGameWindow.getSize().y));
	}


	if (myShouldShowDebugInfo)
	{
		myDebugTool->Update(aDeltaTime);
	}

	myPlayer.Update(aDeltaTime);
	myGameCamera.Update(aDeltaTime);
}

void Game::Render()
{
	myGameWindow.clear(myClearColor);
	
	myGameCamera.UseView(myGameWindow);

	//Todo: Game Rendering
	myTempActor.Render(myGameWindow);
	myPlayer.Render(myGameWindow);

	//GUI Rendering
	myGuiCamera.UseView(myGameWindow);
	myFrame.Render(myGameWindow);
	if (myShouldShowDebugInfo)
	{
		myDebugTool->Render(myGameWindow);
	}

	myGameWindow.display();

}
