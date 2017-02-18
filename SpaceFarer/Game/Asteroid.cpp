#include "Asteroid.h"
#include "..\TextureBank.h"



Asteroid::Asteroid()
{
}

void Asteroid::Init(AsteroidSize aSize, const sf::Vector2f & aPosition)
{
	switch (aSize)
	{
	case AsteroidSize::small:
		Actor::Init(GET_TEXTURE("asteroidSmall"), true, aPosition, 10, 1);
		break;
	case AsteroidSize::standard:
		Actor::Init(GET_TEXTURE("asteroidStandard"), true, aPosition, 20, 0.85f);
		break;
	case AsteroidSize::medium:
		Actor::Init(GET_TEXTURE("asteroidMedium"), true, aPosition, 50, 0.45f);
		break;
	case AsteroidSize::large:
		Actor::Init(GET_TEXTURE("asteroidLarge"), true, aPosition, 100, 0.15f);
		break;
	default:
		break;
	}

	myVelocity.x = cosf(static_cast<float>(rand()));
	myVelocity.y = sinf(static_cast<float>(rand()));
	myVelocity *= static_cast<float>(rand() % 50);
}


Asteroid::~Asteroid()
{
}
