#pragma once
#include "..\Engine\Actor.h"

enum class AsteroidSize
{
	small,
	standard,
	medium,
	large,
	count,
};

class Asteroid : public Actor
{
public:
	Asteroid();
	void Init(AsteroidSize aSize, const sf::Vector2f& aPosition);
	~Asteroid();

};

