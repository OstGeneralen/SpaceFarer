#include "Player.h"
#include <SFML\Window\Event.hpp>
#include <SFML\Window\Keyboard.hpp>
#include "..\Engine\MathTools.h"
#include <cmath>

Player::Player()
{
	myMaxSpeed = 300.f;
	mySpeed = 0;
	myDirection = { 0,0 };
	myRotation = 0;
}

void Player::Update(float aDeltaTime)
{
	Movement(aDeltaTime);
	mySprite.setRotation(MathTools::ToDegrees(myRotation));
}

void Player::Movement(float aDeltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		myRotation += 1.f * aDeltaTime;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		myRotation -= 1.f * aDeltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && mySpeed <= myMaxSpeed)
	{
		mySpeed += 100 * aDeltaTime;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && mySpeed >= 0.f)
	{
		mySpeed -= 200 * aDeltaTime;
	}
	
	if (mySpeed > myMaxSpeed)
	{
		mySpeed = myMaxSpeed;
	}
	else if (mySpeed < 0)
	{
		mySpeed = 0;
	}

	myDirection.x = cosf(myRotation);
	myDirection.y = sinf(myRotation);

	myPosition += myDirection * mySpeed * aDeltaTime;
}
