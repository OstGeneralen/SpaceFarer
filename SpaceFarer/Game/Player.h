#pragma once
#include "..\Engine\Actor.h"

class Player : public Actor
{
public:
	Player();
	void Update(float aDeltaTime) override;
private:
	void Movement(float aDeltaTime);
	sf::Vector2f myDirection;
	float myMaxSpeed;
	float mySpeed;
};