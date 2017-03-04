#include "Player.h"
#include <SFML\Window\Event.hpp>
#include <SFML\Window\Keyboard.hpp>
#include "..\Engine\MathTools.h"
#include <cmath>
#include "SFML\Graphics\RenderWindow.hpp"
#include "Ship\ShipFactory.h"

Player::Player()
{
}

void Player::Update(float aDeltaTime)
{
	myShip->Update(aDeltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
	{
		GiveShip(ShipFactory::GetInstance().BuildShip(ShipModel::Debug));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
	{
		GiveShip(ShipFactory::GetInstance().BuildShip(ShipModel::Standard));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3))
	{
		GiveShip(ShipFactory::GetInstance().BuildShip(ShipModel::Speeder));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4))
	{
		GiveShip(ShipFactory::GetInstance().BuildShip(ShipModel::Cargo));
	}
}

void Player::Render(sf::RenderWindow & aRenderWindow)
{
	myShip->Render(aRenderWindow);
}

void Player::GiveShip(Ship * aShip)
{
	if (myShip != nullptr)
	{
		aShip->SetPosition(myShip->GetPosition());
		aShip->SetTransformable(myShip->GetTransformable());
		aShip->SetVelocity(myShip->GetVelocity());
	}
	myShip = aShip;
	myShip->SetUp(true);

	for (unsigned int index = 0; index < myObservers.size(); ++index)
	{
		myShip->AttatchObserver(myObservers[index]);
	}

	NotifyObservers(EVENT_PLAYER_NEW_SHIP, myShip->GetName());
}

void Player::SetTarget(const sf::Vector2f & aTargetPosition)
{
	NotifyObservers(EVENT_PLAYER_NEW_WAYPOINT, aTargetPosition.x, aTargetPosition.y);
}

Ship* Player::GetShip() const
{
	return myShip;
}
