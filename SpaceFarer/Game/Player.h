#pragma once
#include "..\Engine\Actor.h"
#include "Observer\Subject.h"

class Player : public Actor, public Subject
{
public:
	Player();
	void			Init(sf::Texture* aTexture, bool aOriginIsMiddle = false, const sf::Vector2f& aStartPosition = { 0,0 }) override;
	void			Update(float aDeltaTime) override;
private:
	void			Movement(float aDeltaTime);
	sf::Vector2f	myDirection;
	float			myMaxSpeed;
	float			mySpeed;
	bool			myInertiaEnabled;
};