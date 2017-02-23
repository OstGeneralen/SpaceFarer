#pragma once
#include "Collider.h"

class AABBCollider : public Collider
{
public:
	AABBCollider(const AABB& aAABB);
	AABBCollider(const sf::Vector2f& aPosition, float aWidth, float aHeight);
	
	void			SetPosition(const sf::Vector2f& aPosition) override;
	sf::Vector2f	GetPosition() const override;
	float			GetWidth() const;
	float			GetHeight() const;

	bool			IsCollidingWith(const AABBCollider& aOther) override;
	bool			IsCollidingWith(const CircleCollider& aOther) override;
	bool			IsCollidingWith(const sf::Vector2f& aPoint) override;
private:
	AABB			myAABB;
};