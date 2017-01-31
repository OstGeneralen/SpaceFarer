#include "Game.h"

Game::Game(bool& aShouldRun)
	: myShouldRun(aShouldRun)
{

}

void Game::Init()
{
	myGameWindow.create(sf::VideoMode(800, 800), "SpaceFarer");
	myPlayer.loadFromFile("sprites/player.png");
	myPlayerSprite.setTextureRect({ 0,0,64,64 });
	myPlayerSprite.setTexture(myPlayer);
	myPlayerSprite.setPosition(myPlayerPosition);
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		myPlayerPosition.x += 80 * aDeltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		myPlayerPosition.x -= 80 * aDeltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		myPlayerPosition.y -= 80 * aDeltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		myPlayerPosition.y += 80 * aDeltaTime;
	}

	myPlayerSprite.setPosition(myPlayerPosition);
}

void Game::Render()
{
	myGameWindow.clear(myClearColor);

	//Todo: Add Render code here
	myGameWindow.draw(myPlayerSprite);

	myGameWindow.display();

}
