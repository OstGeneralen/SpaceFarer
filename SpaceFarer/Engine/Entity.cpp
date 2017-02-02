#include "Entity.h"

void Entity::SetPosition(const sf::Vector2f & aPosition)
{
	myPosition = aPosition;
}

const sf::Vector2f & Entity::GetPosition() const
{
	return myPosition;
}
