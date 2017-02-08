#include "Player.h"
#include <SFML\Window\Event.hpp>
#include <SFML\Window\Keyboard.hpp>
#include "..\Engine\MathTools.h"
#include <cmath>
#include "SFML\Graphics\RenderTexture.hpp"

Player::Player()
{
}

void Player::Update(float aDeltaTime)
{
	myShip->Update(aDeltaTime);
}

void Player::Render(sf::RenderTexture & aRenderWindow)
{
	myShip->Render(aRenderWindow);
}

void Player::GiveShip(Ship * aShip)
{
	myShip = aShip;

	for (unsigned int index = 0; index < myObservers.size(); ++index)
	{
		myShip->AttatchObserver(myObservers[index]);
	}

	NotifyObservers(EVENT_PLAYER_NEW_SHIP, myShip->GetName());
}

Ship & Player::GetShip() const
{
	return *myShip;
}
