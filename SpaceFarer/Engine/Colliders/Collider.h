#pragma once
#include "SFML\System\Vector2.hpp"

struct Circle
{
	sf::Vector2f myPosition;
	float myRadius = 0;
};

struct AABB
{
	sf::Vector2f myPosition;
	float myWidth = 0;
	float myHeight = 0;
};

class Collider
{
public:
	Collider() = default;
	virtual void			SetPosition(const sf::Vector2f& aPosition) = 0;
	
	virtual bool			IsCollidingWith(const Circle& aCircle) = 0;
	virtual bool			IsCollidingWith(const AABB& aAABB) = 0;
	virtual bool			IsCollidingWith(const sf::Vector2f& aPoint) = 0;
protected:
};