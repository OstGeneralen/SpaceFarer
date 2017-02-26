#pragma once
#include "Collider.h"

class AABBCollider : public Collider
{
public:
	AABBCollider(const AABB& aAABB);
	AABBCollider(const sf::Vector2f& aPosition, float aWidth, float aHeight);
	
	void			SetPosition(const sf::Vector2f& aPosition) override;
	sf::Vector2f	GetPosition() const override;
	sf::Vector2f	GetTopLeftPoint() const;
	float			GetWidth() const;
	float			GetHeight() const;

	bool			IsCollidingWith(const AABBCollider& aOther) const override;
	bool			IsCollidingWith(const CircleCollider& aOther) const override;
	bool			IsCollidingWith(const sf::Vector2f& aPoint) const override;

	void			Render(sf::RenderWindow& aGameWindow) override;
private:
	AABB			myAABB;
};