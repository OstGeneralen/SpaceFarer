#include "AABBCollider.h"
#include "CircleCollider.h"
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
	myAABB.myTopLeftPoint.x = aPosition.x - aWidth / 2.f;
	myAABB.myTopLeftPoint.y = aPosition.y - aHeight / 2.f;
}

void AABBCollider::SetPosition(const sf::Vector2f & aPosition)
{
	myAABB.myPosition = aPosition;
	myAABB.myTopLeftPoint.x = aPosition.x - myAABB.myWidth / 2.f;
	myAABB.myTopLeftPoint.y = aPosition.y - myAABB.myHeight / 2.f;
}

sf::Vector2f AABBCollider::GetPosition() const
{
	return myAABB.myPosition;
}

sf::Vector2f AABBCollider::GetTopLeftPoint() const
{
	return myAABB.myTopLeftPoint;
}

float AABBCollider::GetWidth() const
{
	return myAABB.myWidth;
}

float AABBCollider::GetHeight() const
{
	return myAABB.myHeight;
}


bool AABBCollider::IsCollidingWith(const AABBCollider& aOther) const
{
	if (aOther.GetTopLeftPoint().x > myAABB.myTopLeftPoint.x + myAABB.myWidth)
	{
		//Is too far right
		return false;
	}
	if (aOther.GetTopLeftPoint().x + aOther.GetWidth() < myAABB.myTopLeftPoint.x)
	{
		//Is too far left
		return false;
	}
	if (aOther.GetTopLeftPoint().y > myAABB.myTopLeftPoint.y + myAABB.myHeight)
	{
		//Is to low
		return false;
	}
	if (aOther.GetTopLeftPoint().y + aOther.GetHeight() < myAABB.myTopLeftPoint.y)
	{
		//Is too high (don't do meth kids)
		return false;
	}

	return true;
}

bool AABBCollider::IsCollidingWith(const CircleCollider& aOther) const 
{
	sf::Vector2f nearestPoint;

	nearestPoint.x = MT::Clamp<float>(nearestPoint.x, myAABB.myTopLeftPoint.x, myAABB.myTopLeftPoint.x + myAABB.myWidth);
	nearestPoint.y = MT::Clamp<float>(nearestPoint.y, myAABB.myTopLeftPoint.y, myAABB.myTopLeftPoint.y + myAABB.myHeight);

	float distance = MT::Length(nearestPoint - aOther.GetPosition());

	if (distance <= aOther.GetRadius())
	{
		return true;
	}

	return false;
}

bool AABBCollider::IsCollidingWith(const sf::Vector2f & aPoint) const
{
	if (aPoint.x > myAABB.myTopLeftPoint.x + myAABB.myWidth)
	{
		//Is too far right
		return false;
	}
	if (aPoint.x < myAABB.myTopLeftPoint.x)
	{
		//Is too far left
		return false;
	}
	if (aPoint.y > myAABB.myTopLeftPoint.y + myAABB.myHeight)
	{
		//Is to low
		return false;
	}
	if (aPoint.y < myAABB.myTopLeftPoint.y)
	{
		//Is too high (don't do meth kids)
		return false;
	}

	return false;
}
