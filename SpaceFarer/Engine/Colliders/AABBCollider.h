#pragma once
#include "Collider.h"

class AABBCollider : public Collider
{
public:
	AABBCollider(const AABB& aAABB);
	AABBCollider(const sf::Vector2f& aPosition, float aWidth, float aHeight);
	
	void			SetPosition(const sf::Vector2f& aPosition) override;
	const AABB&		GetAABB() const;

	bool			IsCollidingWith(const AABB& aOther) override;
	bool			IsCollidingWith(const Circle& aOther) override;
	bool			IsCollidingWith(const sf::Vector2f& aPoint) override;
private:
	AABB			myAABB;
};