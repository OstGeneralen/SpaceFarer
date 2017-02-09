#pragma once
#include "Weapon.h"

class BurstFireWeapon :	public Weapon
{
public:
	BurstFireWeapon();
	~BurstFireWeapon();

	void SpecificUpdate(const float aDeltaTime) override;

protected:
	//ProjectileType* myProjectileType;
	float	myIndividualShotDelay;
	float	myIndividualShotTimer;
	int		myShotsPerBurst;
	int		myShotCount;
};

