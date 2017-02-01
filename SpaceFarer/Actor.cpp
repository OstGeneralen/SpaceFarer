#include "Actor.h"
#include <SFML\Graphics\RenderWindow.hpp>

void Actor::Init(const char * const aTexturePath, const sf::Vector3f& aStartPosition)
{
	myTexture.loadFromFile(aTexturePath);
	mySprite.setTextureRect({ 0,0,myTexture.getSize().x, myTexture.getSize().y });
	mySprite.setTexture(myTexture);
	mySprite.setPosition(aStartPosition.x, aStartPosition.y);
}

void Actor::Render(sf::RenderWindow& aRenderWindow)
{
	aRenderWindow.draw(mySprite);
}
