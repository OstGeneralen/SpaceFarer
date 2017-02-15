#pragma once
#include "Collider.h"
#include "SFML\System\Vector2.hpp"

class CircleCollider : public Collider
{
public:
	void Init(float aRadius, const sf::Vector2f& aPosition);
	//bool CheckIfColliding(const CircleCollider& aCircleCollider) override;
	//bool CheckIfColliding(const AABBCollider& aAABBCollider) override;
	bool CheckIfColliding(const sf::Vector2f& aPoint) override;
private:
	float myRadius;
	sf::Vector2f myPosition;
};