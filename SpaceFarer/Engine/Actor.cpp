#include "Actor.h"
#include <SFML\Graphics\RenderWindow.hpp>

void Actor::Init(const char * const aTexturePath, const sf::Vector2f& aStartPosition)
{
	myTexture.loadFromFile(aTexturePath);
	mySprite.setTextureRect({ 0,0, static_cast<int>(myTexture.getSize().x), static_cast<int>(myTexture.getSize().y) });
	mySprite.setTexture(myTexture);
	mySprite.setPosition(aStartPosition);
}

void Actor::Render(sf::RenderWindow& aRenderWindow)
{
	mySprite.setPosition(myPosition);
	aRenderWindow.draw(mySprite);
}
