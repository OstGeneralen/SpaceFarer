#include "HealthBar.h"

void HealthBar::Init(sf::Texture * aTexture)
{
	Drawable::Init(aTexture);
	mySprite.setColor({ 0,255,0,255 });
	myStartWidth = mySprite.getTextureRect().width;
}

void HealthBar::SetHealth(float aHealth, float aMaxHealth)
{
	if (aHealth < 0)
	{
		aHealth = 0;
	}
	
	sf::Uint8 r = static_cast<sf::Uint8>(255.f * (1.f - (aHealth / aMaxHealth)));
	sf::Uint8 g = static_cast<sf::Uint8>(255.f * (aHealth / aMaxHealth));

	mySprite.setColor({r, g, 0, 255 });

	sf::Rect<int> newRect(0,0,static_cast<int>(myStartWidth * (aHealth / aMaxHealth)), mySprite.getTextureRect().height);
	mySprite.setTextureRect(newRect);
}

void HealthBar::SetPosition(const sf::Vector2f & aPosition)
{
	sf::Vector2f position = aPosition;
	position.x -= mySprite.getLocalBounds().width / 2;
	Drawable::SetPosition(position);
}
