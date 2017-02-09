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
	void					Init(std::vector<Actor*>* aActorListPtr);
	Weapon*					CreateWeapon(WeaponTypes aType, Actor* aOwner, const sf::Vector2f& aOffset = { 75, 0 });
private:
	WeaponFactory();
	bool myIsCreated = false;
	std::vector<Actor*>* myActorListPtr;
};