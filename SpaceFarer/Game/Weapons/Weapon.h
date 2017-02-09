#pragma once
#include <vector>
#include "SFML\Graphics\Transformable.hpp"
#include "SFML\System\Vector2.hpp"
#include "..\..\Engine\Actor.h"

class Weapon
{
public:
	Weapon();
	~Weapon();

	virtual void Init(std::vector<Actor*>* aActorListPtr, Actor* aActor, const sf::Vector2f& aOffset, const float aDelay);
	virtual void Shoot();
	void Update(const float aDeltaTime);

protected:
	virtual void			SpecificUpdate(const float aDeltaTime) = 0;
	void					ResetTimer();

	std::vector<Actor*>*	myActorListPtr;
	Actor*					myActor;
	sf::Transform			myTransform;
	bool					myShouldShoot;
	float					myTimer;
	sf::Vector2f			myOffset;
	float					myDelay;
};