#include "SpaceStation.h"

void SpaceStation::SetExitPoint(ExitPoint aExitPoint)
{
	switch (aExitPoint)
	{
	case ExitPoint::Up:
		myExitPoint = { GetPosition().x, GetPosition().y + mySprite.getLocalBounds().height * 0.75f };
		break;
	case ExitPoint::Down:
		myExitPoint = { GetPosition().x, GetPosition().y + mySprite.getLocalBounds().height * 0.75f };
		break;
	case ExitPoint::Left:
		myExitPoint = {GetPosition().x - mySprite.getLocalBounds().width * 0.75f, GetPosition().y };
		break;
	case ExitPoint::Right:
		myExitPoint = { GetPosition().x + mySprite.getLocalBounds().width * 0.75f, GetPosition().y };
		break;
	default:
		break;
	}
}

const sf::Vector2f & SpaceStation::GetExitPoint() const
{
	return myExitPoint;
}
