#include "Debris.h"
#include "..\TextureBank.h"
#include "SFML\Graphics\RenderWindow.hpp"
#include "..\Engine\Camera.h"
#include "..\Engine\MathTools.h"

void Debris::Update(float aDeltaTime, const Camera& aCamera, const sf::RenderWindow & aRenderWindow)
{
	for (unsigned int index = 0; index < myDebris.size(); ++index)
	{
		if (aCamera.CanSee(myDebris[index]->GetViewHitBox()))
		{
			myDebris[index]->Update(aDeltaTime);
		}

		if (MT::Length(aCamera.GetTargetPosition() - myDebris[index]->GetPosition()) > 3000.f)
		{
			delete myDebris[index];
			myDebris[index] = nullptr;
			myDebris[index] = myDebris.back();
			myDebris.pop_back();
		}
	}

	if (MT::Length(myOldPlayerPosition - myPlayerPosition) > myDistanceBetweenSpawn)
	{
		if (MT::Chance(25))
		{
			SpawnAsteroid(aCamera, aRenderWindow);
		}
	}
}

void Debris::Render(const Camera& aCamera, sf::RenderWindow & aRenderWindow)
{
	for (unsigned int index = 0; index < myDebris.size(); ++index)
	{
		if (aCamera.CanSee(myDebris[index]->GetViewHitBox()))
		{
			myDebris[index]->Render(aRenderWindow);
		}
	}
}

void Debris::HandleCollision(const Camera& aCamera,Actor * aActor)
{
	if (aActor == nullptr)
	{
		for (unsigned int index = 0; index < myDebris.size(); ++index)
		{
			if (aCamera.CanSee(myDebris[index]->GetViewHitBox()))
			{
				for (unsigned int indexTwo = 0; indexTwo < myDebris.size(); ++indexTwo)
				{
					if (index != indexTwo)
					{
						if (aCamera.CanSee(myDebris[indexTwo]->GetViewHitBox()))
						{
							DoCollisionLogic(*myDebris[index], *myDebris[indexTwo]);
						}
					}
				}
			}
		}
	}
	else
	{
		if (aCamera.CanSee(aActor->GetViewHitBox()))
		{
			for (unsigned int index = 0; index < myDebris.size(); ++index)
			{
				if (aCamera.CanSee(myDebris[index]->GetViewHitBox()))
				{
					DoCollisionLogic(*aActor, *myDebris[index]);
				}
			}
		}
	}
}

void Debris::Notify(GameEvent aEvent, float aX, float aY)
{
	if (aEvent == EVENT_PLAYER_NEW_POSITION)
	{
		myPlayerPosition.x = aX;
		myPlayerPosition.y = aX;
	}
}

void Debris::DoCollisionLogic(Actor & aActorOne, Actor & aActorTwo)
{
	if (aActorOne.CheckIfColliding(aActorTwo))
	{
		sf::Vector2f normal = aActorTwo.GetPosition() - aActorOne.GetPosition();
		MT::Normalize(normal);
		sf::Vector2f relativeVel = aActorTwo.GetVelocity() - aActorOne.GetVelocity();
		float velocityScalar = MT::Dot(relativeVel, normal);

		if (velocityScalar > 0)
			return;

		float e = MT::Min(aActorOne.GetRestitution(), aActorTwo.GetRestitution());

		float j = -(1 + e) * velocityScalar;
		j /= ((1.f / aActorOne.GetMass()) + (1.f / aActorTwo.GetMass()));

		//normal *= velocityScalar;
		sf::Vector2f impulse = j * normal;
		aActorOne.ChangeVelocity(-1.f / (aActorOne.GetMass()) * impulse);
		aActorTwo.ChangeVelocity(1.f / (aActorTwo.GetMass()) * impulse);
	}
}

void Debris::SpawnAsteroid(const Camera& aCamera, const sf::RenderWindow& aRenderWindow)
{
	myOldPlayerPosition = myPlayerPosition;


		float x = sinf(static_cast<float>(rand()));
		float y = sinf(static_cast<float>(rand()));

		//The * 2 at the end of theese are to avoid asteroids spawning on-screen.
		//If possible this should be solved in a more elegant way
		x *= static_cast<float>(aRenderWindow.getSize().x) * 2;
		y *= static_cast<float>(aRenderWindow.getSize().y) * 2;

		Asteroid* spawned = new Asteroid();
		spawned->Init(static_cast<AsteroidSize>(rand() % static_cast<int>(AsteroidSize::count)), { aCamera.GetTargetPosition().x + x,aCamera.GetTargetPosition().y + y });

		myDebris.push_back(spawned);
	
}
