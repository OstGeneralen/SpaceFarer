#include "Ship.h"
#include "..\..\Engine\MathTools.h"
#include "SFML\Window\Event.hpp"
#include "..\Weapons\StandardWeapon.h"
#include "..\Weapons\WeaponFactory.h"
#include "..\..\TextureBank.h"
#include "SFML\Graphics\RenderWindow.hpp"

Ship::Ship(ShipFittings aFittings)
{
	/*
	myFittings.myHasInertia = aFittings.myHasInertia;
	myFittings.myFuelTank = aFittings.myFuelTank;
	myFittings.myFuelUsage = aFittings.myFuelUsage;
	myFittings.myAcceleration = aFittings.myAcceleration;
	myFittings.myTurnSpeed = aFittings.myTurnSpeed;
	myFittings.myValue = aFittings.myValue;
	myFittings.myName = aFittings.myName;
	myFittings.myInertiaFactor = aFittings.myInertiaFactor;
	myFittings.myWeaponType = aFittings.myWeaponType;
	*/

	myFittings = aFittings;

	myCurrentFuel = myFittings.myFuelTank;
}

void Ship::SetUp(const bool aOwnedByPlayer)
{
	NotifyObservers(EVENT_PLAYER_NEW_BALANCE, 0);
	NotifyObservers(EVENT_PLAYER_NEW_FUEL_AMOUNT, static_cast<int>(myCurrentFuel));
	NotifyObservers(EVENT_PLAYER_NEW_VELOCITY, 0, 0);
	myWeapon = WeaponFactory::GetInstance().CreateWeapon(myFittings.myWeaponType, this, {75, 0}, aOwnedByPlayer);
	myHealthBar.Init(GET_TEXTURE("HealthBar"));
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Subtract))
	{
		TakeDamage(1);
	}

	Actor::Update(aDeltaTime);
	myWeapon->Update(aDeltaTime);

	myHealthBar.SetPosition({ GetPosition().x, GetPosition().y - mySprite.getLocalBounds().height });

	NotifyObservers(EVENT_PLAYER_NEW_VELOCITY, myVelocity.x, myVelocity.y);
}

void Ship::Render(sf::RenderWindow & aGameWindow)
{
	Actor::Render(aGameWindow);
	myHealthBar.Render(aGameWindow);
}

const sf::String & Ship::GetName() const
{
	return myFittings.myName;
}

void Ship::TakeDamage(float aDamage)
{
	myFittings.myCurrentHealth -= aDamage;
	myHealthBar.SetHealth(myFittings.myCurrentHealth, myFittings.myMaxHealth);
}

void Ship::DoMovement(float aDeltaTime)
{
	float usedFuel = 0;

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
		usedFuel += myFittings.myFuelUsage * aDeltaTime;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		myVelocity -= myDirection * myFittings.myAcceleration * aDeltaTime;
		usedFuel += myFittings.myFuelUsage * aDeltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		myVelocity -= mySideDirection * myFittings.myAcceleration * aDeltaTime;
		usedFuel += myFittings.myFuelUsage * aDeltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		myVelocity += mySideDirection * myFittings.myAcceleration * aDeltaTime;
		usedFuel += myFittings.myFuelUsage * aDeltaTime;
	}

	myCurrentFuel -= usedFuel;

	if (usedFuel > 0)
	{
		NotifyObservers(EVENT_PLAYER_NEW_FUEL_AMOUNT, static_cast<int>(usedFuel));
	}

	mySideDirection.x = cosf(MT::ToRadians(myTransform.getRotation() + 90));
	mySideDirection.y = sinf(MT::ToRadians(myTransform.getRotation() + 90));

	myDirection.x = cosf(MT::ToRadians(myTransform.getRotation()));
	myDirection.y = sinf(MT::ToRadians(myTransform.getRotation()));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		myWeapon->Shoot();
	}

	NotifyObservers(EVENT_PLAYER_NEW_POSITION, GetPosition().x, GetPosition().y);
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
