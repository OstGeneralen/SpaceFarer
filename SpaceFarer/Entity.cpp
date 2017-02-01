#include "Entity.h"

void Entity::SetPosition(const sf::Vector3f & aPosition)
{
	myPosition = aPosition;
}

const sf::Vector3f & Entity::GetPostition() const
{
	return myPosition;
}
