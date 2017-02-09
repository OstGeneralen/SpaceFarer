#include "Drawable.h"
#include "SFML\Graphics\Texture.hpp"
#include "SFML\Graphics\RenderWindow.hpp"
#include "MathTools.h"

void Drawable::Init(sf::Texture * aTexture)
{
	mySprite.setTextureRect({ 0,0, static_cast<int>(aTexture->getSize().x), static_cast<int>(aTexture->getSize().y) });
	mySprite.setTexture(*aTexture);

	myTransform.getTransform().Identity;
}

void Drawable::Render(sf::RenderWindow & aRenderWindow)
{
	aRenderWindow.draw(mySprite);
}

void Drawable::SetRotation(float aRadian)
{
	myTransform.setRotation(MT::ToDegrees(aRadian));
	mySprite.setRotation(myTransform.getRotation());
}

float Drawable::GetRotation() const
{
	return myTransform.getRotation();
}

void Drawable::SetPosition(const sf::Vector2f & aPosition)
{
	myTransform.setPosition(aPosition);
	mySprite.setPosition(myTransform.getPosition());
}

const sf::Vector2f & Drawable::GetPosition() const
{
	return myTransform.getPosition();
}

void Drawable::SetOrigin(const sf::Vector2f & aOrigin)
{
	mySprite.setOrigin(aOrigin);
}

const sf::Vector2f Drawable::GetSpriteDimensions()
{
	return{ mySprite.getLocalBounds().width, mySprite.getLocalBounds().height };
}
