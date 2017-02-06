#include "Player.h"
#include <SFML\Window\Event.hpp>
#include <SFML\Window\Keyboard.hpp>
#include "..\Engine\MathTools.h"
#include <cmath>
#include "SFML\Graphics\RenderWindow.hpp"

Player::Player()
{
}

void Player::Update(float aDeltaTime)
{
	myShip->Update(aDeltaTime);
}

void Player::Render(sf::RenderWindow & aRenderWindow)
{
	myShip->Render(aRenderWindow);
}

void Player::AttatchObserver(Observer * aObserver)
{
	Subject::AttatchObserver(aObserver);
	myShip->AttatchObserver(aObserver);
}

void Player::GiveShip(Ship * aShip)
{
	if (myShip != nullptr)
	{
		delete myShip;
		myShip = nullptr;
	}

	myShip = aShip;
}

Ship & Player::GetShip() const
{
	return *myShip;
}
