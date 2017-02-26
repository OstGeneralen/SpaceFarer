#pragma once
#include "Collider.h"

class CircleCollider : public Collider
{
public:
	CircleCollider(const Circle& aCircle);
	CircleCollider(const sf::Vector2f& aPosition, float aRadius);
	
	void			SetPosition(const sf::Vector2f& aPositon) override;
	sf::Vector2f	GetPosition() const override;
	float			GetRadius() const;
	
	bool			IsCollidingWith(const CircleCollider& aOther) const override;
	bool			IsCollidingWith(const AABBCollider& aOther) const override;
	bool			IsCollidingWith(const sf::Vector2f& aPoint) const override;
private:
	Circle			myCircle;
};