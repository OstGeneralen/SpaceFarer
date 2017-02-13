#include "Game.h"
#include "..\Engine\DebugTools\FPSCounter.h"
#include "..\Engine\DebugTools\VersionStamp.h"
#include "States\StateManger.h"
#include "..\TextureBank.h"
#include <fstream>

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

}

void Game::Init()
{
	myGameWindow.create(sf::VideoMode::getDesktopMode(), "SpaceFarer V: " + std::to_string(MAJOR) + "." + std::to_string(MINOR) + "." + std::to_string(PATCH));

	StateManager::GetInstance().ChangeState(GameState::Menu, myGameWindow);

	myDebugTool = new D::FPSCounter(new D::VersionStamp(new D::Tools()));
	myDebugTool->Load(myGameWindow);

	std::ifstream inStream("json/master.json");
	myMasterJson << inStream;

	TextureBank::GetInstance().LoadTextures(myMasterJson["texturesPath"]);

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
		
	}

	if (myShouldShowDebugInfo)
	{
		myDebugTool->Update(aDeltaTime);
	}

	StateManager::GetInstance().Update(aDeltaTime);
}

void Game::Render()
{
	myGameWindow.clear(myClearColor);
	
	StateManager::GetInstance().Render();

	myDebugCamera.UseView(myGameWindow);
	if (myShouldShowDebugInfo)
	{
		myDebugTool->Render(myGameWindow);
	}
	
	myGameWindow.display();
}