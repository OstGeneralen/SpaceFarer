#pragma once
#include "Player.h"
#include "Station\SpaceStation.h"
#include "SFML\Graphics\RenderWindow.hpp"

struct GameData
{
	SpaceStation* myLastVisitedStation = nullptr;
	Player* myPlayer = nullptr;
	sf::RenderWindow* myGameWindow = nullptr;
};