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
	myFuel = 100000;
	myFuelConsumption = 1;
}

void Player::Init(sf::Texture * aTexture, bool aOriginIsMiddle, const sf::Vector2f & aStartPosition)
{
	Actor::Init(aTexture, aOriginIsMiddle, aStartPosition);
	NotifyObservers(EVENT_PLAYER_NEW_BALANCE, 0);
	NotifyObservers(EVENT_PLAYER_NEW_FUEL_AMOUNT, myFuel);
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

	if (myFuel < 0)
	{
		myFuel = 0;
	}

	if (myFuel > 0)
	{
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
			myFuel -= myFuelConsumption;
			NotifyObservers(EVENT_PLAYER_NEW_FUEL_AMOUNT, myFuel);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && mySpeed >= 0.f)
		{
			myVelocity -= myDirection * 200.f * aDeltaTime;
			myFuel -= myFuelConsumption;
			NotifyObservers(EVENT_PLAYER_NEW_FUEL_AMOUNT, myFuel);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I))
		{
			myInertiaEnabled = true;
			myFuel -= myFuelConsumption * 2;
			NotifyObservers(EVENT_PLAYER_NEW_FUEL_AMOUNT, myFuel);
		}
	}

	if (myInertiaEnabled)
	{
		myVelocity.x = MathTools::Lerp(myVelocity.x, 0, 2.5f * aDeltaTime);
		myVelocity.y = MathTools::Lerp(myVelocity.y, 0, 2.5f * aDeltaTime);
		
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
