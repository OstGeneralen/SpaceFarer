#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

class Game
{
public:
	Game(bool& aShouldRun);
	void Init();
	void Update(float aDeltaTime);
	void Render();
private:
	sf::RenderWindow myGameWindow;
	const sf::Color myClearColor = sf::Color(0, 150, 255, 255);
	sf::Texture myPlayer;
	sf::Sprite myPlayerSprite;
	sf::Vector2f myPlayerPosition = { 0,0 };
	bool& myShouldRun;
};