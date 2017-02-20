#include "Game.h"
#include "..\Engine\DebugTools\FPSCounter.h"
#include "..\Engine\DebugTools\VersionStamp.h"
#include "States\StateManger.h"
#include "..\TextureBank.h"
#include "..\Engine\Animation\AnimationFactory.h"
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
#ifdef _DEBUG
	myGameWindow.create(sf::VideoMode::getDesktopMode(), "SpaceFarer V: " + VERSION_STRING);
#else
	myGameWindow.create(sf::VideoMode::getDesktopMode(), "SpaceFarer V: " + VERSION_STRING, sf::Style::Fullscreen);
#endif

	myGameWindow.setMouseCursorVisible(false);

	myDebugTool = new D::FPSCounter(new D::VersionStamp(new D::Tools()));
	myDebugTool->Load(myGameWindow);

	std::ifstream inStream("json/master.json");
	myMasterJson << inStream;
	TextureBank::GetInstance().LoadTextures(myMasterJson["texturesPath"]);
	AnimationFactory::GetInstance().Init(myMasterJson["animationsPath"]);
	
#ifdef _DEBUG
	StateManager::GetInstance().ChangeState(GameState::Menu, myGameWindow);
#else
	StateManager::GetInstance().ChangeState(GameState::Splash, myGameWindow);
#endif

	myCursor.Init(GET_TEXTURE("Cursor"));

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
	myCursor.Render(myGameWindow);
	if (myShouldShowDebugInfo)
	{
		myDebugTool->Render(myGameWindow);
	}
	
	myGameWindow.display();
}