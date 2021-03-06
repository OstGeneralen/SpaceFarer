#pragma once
#include <vector>
#include "SFML\Graphics\Transformable.hpp"
#include "SFML\System\Vector2.hpp"
#include "..\..\Engine\Actor.h"
#include "..\Bullets\BulletManager.h"
#include "..\Bullets\Projectile.h"

class Weapon
{
public:
	Weapon();
	~Weapon();

	virtual void Init(Actor* aActor, const sf::Vector2f& aOffset, const float aDelay, const bool aOwnedByPlayer = false);
	virtual void Shoot();
	void Update(const float aDeltaTime);

protected:
	virtual void			SpecificUpdate(const float aDeltaTime) = 0;
	void					ResetTimer();

	Actor*					myActor;
	sf::Transform			myTransform;
	bool					myShouldShoot;
	float					myTimer;
	sf::Vector2f			myOffset;
	float					myDelay;
	bool					myIsOwnedByPlayer;
};