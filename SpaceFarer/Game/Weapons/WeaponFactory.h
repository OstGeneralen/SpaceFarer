#pragma once
#include "Weapon.h"

enum class WeaponTypes
{
	Standard,
	BurstFire,
};

class WeaponFactory
{
public:
	static WeaponFactory&	GetInstance();
	void					Init();
	Weapon*					CreateWeapon(WeaponTypes aType, Actor* aOwner, const sf::Vector2f& aOffset = { 75, 0 }, const bool aIsOwnedByPlayer = false);
private:
	WeaponFactory();
	bool myIsCreated = false;
};