#include "WeaponFactory.h"
#include <iostream>
#include <assert.h>

#include "StandardWeapon.h"
#include "BurstFireWeapon.h"

void WeaponFactory::Init(std::vector<Actor*>* aActorListPtr)
{
	myActorListPtr = aActorListPtr;
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

Weapon * WeaponFactory::CreateWeapon(WeaponTypes aType, Actor* aOwner, const sf::Vector2f & aOffset)
{
	assert(myActorListPtr != nullptr && "ActorList is null, try running Init.");
	Weapon* returnWeapon = nullptr;
	switch (aType)
	{
	case WeaponTypes::Standard:
		returnWeapon = new StandardWeapon();
		returnWeapon->Init(myActorListPtr, aOwner, aOffset, 0.15f);
		break;
	case WeaponTypes::BurstFire:
		returnWeapon = new BurstFireWeapon();
		returnWeapon->Init(myActorListPtr, aOwner, aOffset, 0.5f);
		break;
	default:
		std::cout << "Tried to assign non-existing weapon type, defaulting to StandardWeapon." << std::endl << std::endl;
		returnWeapon = new StandardWeapon();
		returnWeapon->Init(myActorListPtr, aOwner, aOffset, 0.25f);
		break;
	}
	return returnWeapon;
}

WeaponFactory::WeaponFactory()
{
}
