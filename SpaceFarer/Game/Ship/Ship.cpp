#include "Ship.h"
#include "..\..\Engine\MathTools.h"
#include "SFML\Window\Event.hpp"

Ship::Ship(ShipFittings aFittings)
{
	myFittings.myHasInertia = aFittings.myHasInertia;
	myFittings.myFuelTank = aFittings.myFuelTank;
	myFittings.myFuelUsage = aFittings.myFuelUsage;
	myFittings.myAcceleration = aFittings.myAcceleration;
	myFittings.myTurnSpeed = aFittings.myTurnSpeed;
	myFittings.myValue = aFittings.myValue;
	myFittings.myName = aFittings.myName;
	myFittings.myInertiaFactor = aFittings.myInertiaFactor;

	myCurrentFuel = myFittings.myFuelTank;
}

void Ship::SetUp()
{
	NotifyObservers(EVENT_PLAYER_NEW_BALANCE, 0);
	NotifyObservers(EVENT_PLAYER_NEW_FUEL_AMOUNT, static_cast<int>(myCurrentFuel));
	NotifyObservers(EVENT_PLAYER_NEW_VELOCITY, 0, 0);
}

void Ship::Update(float aDeltaTime)
{
	if (myCurrentFuel < 0)
	{
		myCurrentFuel = 0;
	}

	if (myCurrentFuel > 0)
	{
		DoMovement(aDeltaTime);

		if (myFittings.myHasInertia)
		{
			UpdateInertia(aDeltaTime);
		}

	}

	Actor::Update(aDeltaTime);

	NotifyObservers(EVENT_PLAYER_NEW_VELOCITY, myVelocity.x, myVelocity.y);
}

const sf::String & Ship::GetName() const
{
	return myFittings.myName;
}

void Ship::DoMovement(float aDeltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		myTransform.rotate(myFittings.myTurnSpeed * aDeltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		myTransform.rotate(-(myFittings.myTurnSpeed * aDeltaTime));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		myVelocity += myDirection * myFittings.myAcceleration * aDeltaTime;
		myCurrentFuel -= myFittings.myFuelUsage * aDeltaTime;
		NotifyObservers(EVENT_PLAYER_NEW_FUEL_AMOUNT, static_cast<int>(myCurrentFuel));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		myVelocity -= myDirection * myFittings.myAcceleration * aDeltaTime;
		myCurrentFuel -= myFittings.myFuelUsage * aDeltaTime;
		NotifyObservers(EVENT_PLAYER_NEW_FUEL_AMOUNT, static_cast<int>(myCurrentFuel));
	}

	myDirection.x = cosf(MT::ToRadians(myTransform.getRotation()));
	myDirection.y = sinf(MT::ToRadians(myTransform.getRotation()));
}

void Ship::UpdateInertia(float aDeltaTime)
{
	myInertiaEnabled = false;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I))
	{
			myInertiaEnabled = true;
			myCurrentFuel -= myFittings.myFuelUsage * 2 * aDeltaTime;
			NotifyObservers(EVENT_PLAYER_NEW_FUEL_AMOUNT, static_cast<int>(myCurrentFuel));
	}

	if (myInertiaEnabled)
	{
		myVelocity = MathTools::Lerp(myVelocity, { 0,0 }, myFittings.myInertiaFactor * aDeltaTime);

		if (abs(myVelocity.x - 0.f) < 0.1f)
		{
			myVelocity.x = 0;
		}
		if (abs(myVelocity.y - 0.f) < 0.1f)
		{
			myVelocity.y = 0;
		}
	}
	
}
