#include "Player.h"
#include <SFML\Window\Event.hpp>
#include <SFML\Window\Keyboard.hpp>
#include "..\Engine\MathTools.h"

Player::Player()
{
	myMaxSpeed = 300.f;
	mySpeed = 0;
	myDirection = { 0,0 };
}

void Player::Update(float aDeltaTime)
{
	Movement(aDeltaTime);
}

void Player::Movement(float aDeltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		myDirection.x = MathTools::Lerp(myDirection.x, 1, 1.0f * aDeltaTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		myDirection.x = MathTools::Lerp(myDirection.x, -1, 1.0f * aDeltaTime);
	}
	else
	{
		myDirection.x = MathTools::Lerp(myDirection.x, 0, 2.0f * aDeltaTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		myDirection.y = MathTools::Lerp(myDirection.y, -1, 1.0f * aDeltaTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		myDirection.y = MathTools::Lerp(myDirection.y, 1, 1.0f * aDeltaTime);
	}
	else
	{
		myDirection.y = MathTools::Lerp(myDirection.y, 0, 2.0f * aDeltaTime);
	}
	myPosition += myDirection * myMaxSpeed * aDeltaTime;
}
