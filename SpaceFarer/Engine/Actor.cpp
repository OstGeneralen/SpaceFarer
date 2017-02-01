#include "Actor.h"
#include <SFML\Graphics\RenderWindow.hpp>
#include "MathTools.h"

void Actor::Init(const char * const aTexturePath, bool aOriginIsMiddle, const sf::Vector2f& aStartPosition)
{
	myTexture.loadFromFile(aTexturePath);
	mySprite.setTextureRect({ 0,0, static_cast<int>(myTexture.getSize().x), static_cast<int>(myTexture.getSize().y) });
	mySprite.setTexture(myTexture);

	if (aOriginIsMiddle)
	{
		MathTools::MTVector2 middlePoint;
		middlePoint = MathTools::GetMiddlePoint(0, 0, mySprite.getTextureRect().width, mySprite.getTextureRect().height);
		mySprite.setOrigin({ middlePoint.x, middlePoint.y });
	}

	mySprite.setPosition(aStartPosition);
}

void Actor::Render(sf::RenderWindow& aRenderWindow)
{
	mySprite.setPosition(myPosition);
	aRenderWindow.draw(mySprite);
}
