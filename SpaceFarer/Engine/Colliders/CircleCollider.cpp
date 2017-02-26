#include "CircleCollider.h"
#include "AABBCollider.h"
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

float CircleCollider::GetRadius() const
{
	return myCircle.myRadius;
}

bool CircleCollider::IsCollidingWith(const CircleCollider& aOther) const
{
	float distance = MT::Length(myCircle.myPosition - aOther.GetPosition());

	if (distance < (myCircle.myRadius + aOther.GetRadius()))
	{
		return true;
	}

	return false;
}

bool CircleCollider::IsCollidingWith(const AABBCollider& aOther) const
{
	sf::Vector2f nearestPoint;

	nearestPoint.x = MT::Clamp<float>(nearestPoint.x, aOther.GetTopLeftPoint().x, aOther.GetTopLeftPoint().x + aOther.GetWidth());
	nearestPoint.y = MT::Clamp<float>(nearestPoint.y, aOther.GetTopLeftPoint().y, aOther.GetTopLeftPoint().y + aOther.GetHeight());

	float distance = MT::Length(nearestPoint - myCircle.myPosition);

	if (distance <= myCircle.myRadius)
	{
		return true;
	}

	return false;
}

bool CircleCollider::IsCollidingWith(const sf::Vector2f & aPoint) const
{
	if (MT::Length(myCircle.myPosition - aPoint) < myCircle.myRadius)
	{
		return true;
	}

	return false;
}
