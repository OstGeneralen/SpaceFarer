#include "Game.h"
#include "..\Engine\DebugTools\FPSCounter.h"
#include "..\Engine\DebugTools\VersionStamp.h"
#include "..\Engine\MathTools.h"
#include "..\TextureBank.h"


#define RANDOM_SEED 25062009

Game::Game(bool& aShouldRun)
	: myShouldRun(aShouldRun)
{
#ifdef _DEBUG
	myShouldShowDebugInfo = true;
	srand(RANDOM_SEED);
#else
	myShouldShowDebugInfo = false;
#endif

	myDebugTool = new D::FPSCounter(new D::VersionStamp(new D::Tools()));
	myDebugTool->Load(myGameWindow);
}

void Game::Init()
{
	myGameState = GameState::Menu;

	myGameWindow.create(sf::VideoMode::getDesktopMode(), "SpaceFarer");
	TextureBank::GetInstance()->Load();

	myFlyingState.Load(&myGameWindow);
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

	if (e.type == sf::Event::Resized)
	{
		myDebugTool->Load(myGameWindow);
		myFlyingState.WindowResize();
	}

	if (myShouldShowDebugInfo)
	{
		myDebugTool->Update(aDeltaTime);
	}

	switch (myGameState)
	{
	case GameState::Flying:
		if (!myFlyingState.GetIsLoaded())
		{
			myFlyingState.Load(&myGameWindow);
			break;
		}
		myFlyingState.Update(aDeltaTime, myGameState);
		break;
	case GameState::Menu:
		if (!myMenuState.GetIsLoaded())
		{
			myMenuState.Load(&myGameWindow);
			break;
		}
		myMenuState.Update(aDeltaTime, myGameState);
	default:
		break;
	}

}

void Game::Render()
{
	myGameWindow.clear(myClearColor);
	
	switch (myGameState)
	{
	case GameState::Flying:
		if (myFlyingState.GetIsLoaded())
		{
			myFlyingState.Render();
		}
		break;
	case GameState::Menu:
		if (myMenuState.GetIsLoaded())
		{
			myMenuState.Render();
		}
	default:
		break;
	}

	myDebugCamera.UseView(myGameWindow);
	if (myShouldShowDebugInfo)
	{
		myDebugTool->Render(myGameWindow);
	}

	myGameWindow.display();
}
