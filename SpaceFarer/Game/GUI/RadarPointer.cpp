#include "RadarPointer.h"
#include "..\..\TextureBank.h"
#include "SFML\Graphics\RenderWindow.hpp"
#include "..\..\Engine\MathTools.h"
#include <cmath>


void RadarPointer::SetTargetPosition(const sf::Vector2f & aTargetPosition)
{
	myTargetPosition = aTargetPosition;
}

void RadarPointer::Update(const sf::Vector2f & aPlayerPosition)
{
	myDirection = myTargetPosition - aPlayerPosition;
	MT::Normalize(myDirection);

	myTransform.setRotation(MT::ToDegrees(atan2(myDirection.y, myDirection.x)));

	mySprite.setRotation(myTransform.getRotation());
}
