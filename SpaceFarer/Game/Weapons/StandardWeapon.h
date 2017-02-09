#pragma once
#include "..\..\Game\Weapons\Weapon.h"


class StandardWeapon : public Weapon
{
public:
	StandardWeapon();
	~StandardWeapon();

	void SpecificUpdate(const float aDeltaTime) override;

protected:
	//ProjectileType* myProjectileType;
};

