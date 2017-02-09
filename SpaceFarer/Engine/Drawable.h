#pragma once
#include "Entity.h"
#include "SFML\Graphics\Transformable.hpp"
#include "SFML\Graphics\Sprite.hpp"

namespace sf
{
	class RenderWindow;
	class Texture;
}

class Drawable : public Entity
{
public:
	Drawable() = default;
	virtual void			Init(sf::Texture* aTexture);
	virtual void			Render(sf::RenderWindow& aRenderWindow);
	
	virtual void			SetRotation(float aRadian);
	float					GetRotation() const;
	
	virtual void			SetPosition(const sf::Vector2f& aPosition);
	const sf::Vector2f&		GetPosition() const;

	void					SetOrigin(const sf::Vector2f& aOrigin);

	const sf::Vector2f		GetSpriteDimensions();
protected:
	sf::Transformable		myTransform;
	sf::Sprite				mySprite;
};