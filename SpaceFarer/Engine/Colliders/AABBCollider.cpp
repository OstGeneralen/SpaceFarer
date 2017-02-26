#include "AABBCollider.h"
#include "..\MathTools.h"

AABBCollider::AABBCollider(const AABB & aAABB)
{
	myAABB = aAABB;
}

AABBCollider::AABBCollider(const sf::Vector2f & aPosition, float aWidth, float aHeight)
{
	myAABB.myPosition = aPosition;
	myAABB.myWidth = aWidth;
	myAABB.myHeight = aHeight;
}

void AABBCollider::SetPosition(const sf::Vector2f & aPosition)
{
	myAABB.myPosition = aPosition;
}

const AABB & AABBCollider::GetAABB() const
{
	return myAABB;
}

bool AABBCollider::IsCollidingWith(const AABB& aOther)
{
	if (aOther.myPosition.x > myAABB.myPosition.x + myAABB.myWidth)
	{
		//Is too far right
		return false;
	}
	if (aOther.myPosition.x + aOther.myWidth < myAABB.myPosition.x)
	{
		//Is too far left
		return false;
	}
	if (aOther.myPosition.y > myAABB.myPosition.y + myAABB.myHeight)
	{
		//Is to low
		return false;
	}
	if (aOther.myPosition.y + aOther.myHeight < myAABB.myPosition.y)
	{
		//Is too high (don't do meth kids)
		return false;
	}

	return true;
}

bool AABBCollider::IsCollidingWith(const Circle & aOther)
{
	sf::Vector2f nearestPoint;

	nearestPoint.x = MT::Clamp<float>(nearestPoint.x, myAABB.myPosition.x, myAABB.myPosition.x + myAABB.myWidth);
	nearestPoint.y = MT::Clamp<float>(nearestPoint.y, myAABB.myPosition.y, myAABB.myPosition.y + myAABB.myHeight);

	float distance = MT::Length(nearestPoint - aOther.myPosition);

	if (distance <= aOther.myRadius)
	{
		return true;
	}

	return false;
}

bool AABBCollider::IsCollidingWith(const sf::Vector2f & aPoint)
{
	if (aPoint.x > myAABB.myPosition.x + myAABB.myWidth)
	{
		//Is too far right
		return false;
	}
	if (aPoint.x < myAABB.myPosition.x)
	{
		//Is too far left
		return false;
	}
	if (aPoint.y > myAABB.myPosition.y + myAABB.myHeight)
	{
		//Is to low
		return false;
	}
	if (aPoint.y < myAABB.myPosition.y)
	{
		//Is too high (don't do meth kids)
		return false;
	}

	return false;
}
