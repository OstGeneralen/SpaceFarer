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

const Circle & CircleCollider::GetCircle() const
{
	return myCircle;
}

bool CircleCollider::IsCollidingWith(const Circle& aOther)
{
	float distance = MT::Length(myCircle.myPosition - aOther.myPosition);

	if (distance < (myCircle.myRadius + aOther.myRadius))
	{
		return true;
	}

	return false;
}

bool CircleCollider::IsCollidingWith(const AABB& aOther)
{
	sf::Vector2f nearestPoint;

	nearestPoint.x = MT::Clamp<float>(nearestPoint.x, aOther.myPosition.x, aOther.myPosition.x + aOther.myWidth);
	nearestPoint.y = MT::Clamp<float>(nearestPoint.y, aOther.myPosition.y, aOther.myPosition.y + aOther.myHeight);

	float distance = MT::Length(nearestPoint - myCircle.myPosition);

	if (distance <= myCircle.myRadius)
	{
		return true;
	}

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
