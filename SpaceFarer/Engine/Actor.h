#pragma once
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Vector2.hpp>
#include "Entity.h"

namespace sf
{
	class RenderWindow;
}

class Actor : public Entity
{
public:
	virtual void				Init(sf::Texture* aTexture, bool aOriginIsMiddle = false, const sf::Vector2f& aStartPosition = { 0,0});
	virtual void				Update(float aDeltaTime);
	void						Render(sf::RenderWindow& aRenderWindow);
	void						SetPosition(const sf::Vector2f& aPosition) override;
	const sf::Vector2f&			GetPosition() const override;
	const sf::Vector2f&			GetSize() const;
	const sf::Transform&		GetTransform() const;
	void						SetVelocity(const sf::Vector2f& aVelocity);
	const sf::Vector2f&			GetVelocity() const;
	void						ChangeVelocity(const sf::Vector2f& aVelocity);
	const float					GetRadius() const;
protected:
	sf::Texture*				myTexture = nullptr;
	sf::Sprite					mySprite;
	sf::Transformable			myTransform;
	sf::Vector2f				myVelocity;
	float						myMass;
};