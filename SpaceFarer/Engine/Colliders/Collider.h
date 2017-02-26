#pragma once
#include "SFML\System\Vector2.hpp"

class CircleCollider;
class AABBCollider;

struct Circle
{
	sf::Vector2f myPosition;
	float myRadius = 0;
};

struct AABB
{
	sf::Vector2f myPosition;
	sf::Vector2f myTopLeftPoint;
	float myWidth = 0;
	float myHeight = 0;
};

class Collider
{
public:
	Collider() = default;
	virtual void			SetPosition(const sf::Vector2f& aPosition) = 0;
	virtual sf::Vector2f	GetPosition() const = 0;
	
	virtual bool			IsCollidingWith(const CircleCollider& aOther) const = 0;
	virtual bool			IsCollidingWith(const AABBCollider& aOther) const = 0;
	virtual bool			IsCollidingWith(const sf::Vector2f& aPoint) const = 0;
protected:
};