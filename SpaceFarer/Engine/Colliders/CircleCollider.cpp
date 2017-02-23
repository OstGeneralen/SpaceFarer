#include "CircleCollider.h"
#include "SFML\System\Vector2.hpp"
#include "..\MathTools.h"

CircleCollider::CircleCollider(const Circle & aCircle)
{
	myCircle = aCircle;
}

CircleCollider::CircleCollider(const sf::Vector2f & aPosition, float aRadius)
{
	myCircle.myPosition = aPosition;
	myCircle.myRadius = aRadius;
}

void CircleCollider::SetPosition(const sf::Vector2f & aPositon)
{
	myCircle.myPosition = aPositon;
}

sf::Vector2f CircleCollider::GetPosition() const
{
	return myCircle.myPosition;
}

bool CircleCollider::IsCollidingWith(const CircleCollider& aOther)
{
	float distance = MT::Length(myCircle.myPosition - aOther.GetPosition);

	if (distance < (myCircle.myRadius + aOther.GetRadius()))
	{
		return true;
	}

	return false;
}

bool CircleCollider::IsCollidingWith(const AABBCollider & aOther)
{
	return false;
}

bool CircleCollider::IsCollidingWith(const sf::Vector2f & aPoint)
{
	if (MT::Length(myCircle.myPosition - aPoint) < myCircle.myRadius)
	{
		return true;
	}

	return false;
}

float CircleCollider::GetRadius() const
{
	return myCircle.myRadius;
}
