#include "Game.h"

Game::Game(bool& aShouldRun)
	: myShouldRun(aShouldRun)
{

}

void Game::Init()
{
	myGameWindow.create(sf::VideoMode(800, 800), "SpaceFarer");
	myPlayer.Init("sprites/player.png");
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

	myPlayer.Update(aDeltaTime);

}

void Game::Render()
{
	myGameWindow.clear(myClearColor);

	//Todo: Add Render code here
	myPlayer.Render(myGameWindow);

	myGameWindow.display();

}
