#include "CircleCollider.h"
#include "..\MathTools.h"



void CircleCollider::Init(float aRadius, const sf::Vector2f& aPosition)
{
	myRadius = aRadius;
	myPosition = aPosition;
}

/*bool CircleCollider::CheckIfColliding(const CircleCollider & aCircleCollider)
{

	return false;
}*/

/*bool CircleCollider::CheckIfColliding(const AABBCollider & aAABBCollider)
{
	return false;
}*/

bool CircleCollider::CheckIfColliding(const sf::Vector2f & aPoint)
{
	return false;
}
