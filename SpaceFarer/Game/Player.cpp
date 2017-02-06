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
	myInertiaEnabled = false;
}

void Player::Init(sf::Texture * aTexture, bool aOriginIsMiddle, const sf::Vector2f & aStartPosition)
{
	Actor::Init(aTexture, aOriginIsMiddle, aStartPosition);
	NotifyObservers(EVENT_PLAYER_NEW_BALANCE, 0);
	NotifyObservers(EVENT_PLAYER_NEW_VELOCITY, 0, 0);
}

void Player::Update(float aDeltaTime)
{
	myTransform.move(myVelocity * aDeltaTime);
	Movement(aDeltaTime);

	NotifyObservers(EVENT_PLAYER_NEW_VELOCITY, myVelocity.x, myVelocity.y);
}

void Player::Movement(float aDeltaTime)
{
	myInertiaEnabled = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		myTransform.rotate(MT::ToDegrees(static_cast<float>(MT_PI) * aDeltaTime));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		myTransform.rotate(-MT::ToDegrees(static_cast<float>(MT_PI) * aDeltaTime));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && mySpeed <= myMaxSpeed)
	{
		myVelocity += myDirection * 200.f * aDeltaTime;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && mySpeed >= 0.f)
	{
		myVelocity -= myDirection * 200.f * aDeltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I))
	{
		myInertiaEnabled = true;
	}

	if (myInertiaEnabled)
	{
		myVelocity.x = MathTools::Lerp(myVelocity.x, 0, 2.f * aDeltaTime);
		myVelocity.y = MathTools::Lerp(myVelocity.y, 0, 2.f * aDeltaTime);
		
		if (abs(myVelocity.x - 0.f) < 0.1f)
		{
			myVelocity.x = 0;
		}
		if (abs(myVelocity.y - 0.f) < 0.1f)
		{
			myVelocity.y = 0;
		}
	}
	
	if (mySpeed > myMaxSpeed)
	{
		mySpeed = myMaxSpeed;
	}
	else if (mySpeed < 0)
	{
		mySpeed = 0;
	}

	myDirection.x = cosf(MT::ToRadians(myTransform.getRotation()));
	myDirection.y = sinf(MT::ToRadians(myTransform.getRotation()));

	myTransform.move(myVelocity * aDeltaTime);
}
