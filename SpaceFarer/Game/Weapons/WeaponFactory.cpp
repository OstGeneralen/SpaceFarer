#include "WeaponFactory.h"
#include <iostream>
#include <assert.h>

#include "StandardWeapon.h"
#include "BurstFireWeapon.h"

void WeaponFactory::Init()
{
}

WeaponFactory & WeaponFactory::GetInstance()
{
	static WeaponFactory* instance = new WeaponFactory();

	if (!instance->myIsCreated)
	{
		instance->myIsCreated = true;
	}

	return *instance;
}

Weapon * WeaponFactory::CreateWeapon(WeaponTypes aType, Actor* aOwner, const sf::Vector2f & aOffset, const bool aIsOwnedByPlayer)
{
	Weapon* returnWeapon = nullptr;
	switch (aType)
	{
	case WeaponTypes::Standard:
		returnWeapon = new StandardWeapon();
		returnWeapon->Init(aOwner, aOffset, 0.15f, aIsOwnedByPlayer);
		break;
	case WeaponTypes::BurstFire:
		returnWeapon = new BurstFireWeapon();
		returnWeapon->Init(aOwner, aOffset, 0.5f, aIsOwnedByPlayer);
		break;
	default:
		std::cout << "Tried to assign non-existing weapon type, defaulting to StandardWeapon." << std::endl << std::endl;
		returnWeapon = new StandardWeapon();
		returnWeapon->Init(aOwner, aOffset, 0.25f);
		break;
	}
	return returnWeapon;
}

WeaponFactory::WeaponFactory()
{
}
