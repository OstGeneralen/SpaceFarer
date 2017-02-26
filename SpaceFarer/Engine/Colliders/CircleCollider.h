#pragma once
#include "Collider.h"

class CircleCollider : public Collider
{
public:
	CircleCollider(const Circle& aCircle);
	CircleCollider(const sf::Vector2f& aPosition, float aRadius);
	
	void			SetPosition(const sf::Vector2f& aPositon) override;
	const Circle&	GetCircle() const;
	
	bool			IsCollidingWith(const Circle& aOther) override;
	bool			IsCollidingWith(const AABB& aOther) override;
	bool			IsCollidingWith(const sf::Vector2f& aPoint) override;
private:
	Circle			myCircle;
};