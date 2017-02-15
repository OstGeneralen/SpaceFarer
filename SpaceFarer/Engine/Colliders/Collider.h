#pragma once
//#include "CircleCollider.h"
//#include "AABBCollider.h"

namespace sf
{
	class Vector2f;
}

class Collider
{
public:
	//virtual bool CheckIfColliding(const CircleCollider& aOther) = 0;
	//virtual bool CheckIfColliding(const AABBCollider& aOther) = 0;
 	virtual bool CheckIfColliding(const sf::Vector2f& aPoint) = 0;
};