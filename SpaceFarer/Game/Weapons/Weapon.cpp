#include "Weapon.h"

Weapon::Weapon()
{
	myTimer = 0;
}


Weapon::~Weapon()
{
}

void Weapon::Shoot()
{
	if (myTimer >= myDelay)
	{
		myShouldShoot = true;
	}
}

void Weapon::Init(std::vector<Actor*>* aActorListPtr, Actor * aActor, const sf::Vector2f& aOffset, const float aDelay)
{
	myActorListPtr = aActorListPtr;
	myActor = aActor;
	myOffset = aOffset;
	myDelay = aDelay;
}

void Weapon::Update(const float aDeltaTime)
{
	myTimer += aDeltaTime;
	myTransform *= myActor->GetTransform();

	SpecificUpdate(aDeltaTime);
}

void Weapon::ResetTimer()
{
	myShouldShoot = false;
	myTimer = 0;
}
