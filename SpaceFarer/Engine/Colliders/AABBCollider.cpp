#include "AABBCollider.h"

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

sf::Vector2f AABBCollider::GetPosition() const
{
	return myAABB.myPosition;
}

float AABBCollider::GetWidth() const
{
	return myAABB.myWidth;
}

float AABBCollider::GetHeight() const
{
	return myAABB.myHeight;
}

bool AABBCollider::IsCollidingWith(const AABBCollider & aOther)
{
	return false;
}

bool AABBCollider::IsCollidingWith(const CircleCollider & aOther)
{
	return false;
}

bool AABBCollider::IsCollidingWith(const sf::Vector2f & aPoint)
{
	return false;
}
