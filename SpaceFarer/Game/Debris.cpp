#include "Debris.h"
#include "..\TextureBank.h"
#include "SFML\Graphics\RenderWindow.hpp"
#include "..\Engine\Camera.h"
#include "..\Engine\MathTools.h"
#include "..\Game\CollisionManager.h"

void Debris::Init()
{
	CollisionManager::GetInstance().SetDebrisList(&myDebris);
}

void Debris::Update(float aDeltaTime, const Camera& aCamera, const sf::RenderWindow & aRenderWindow)
{
	for (unsigned int index = 0; index < myDebris.size(); ++index)
	{
		if (aCamera.CanSee(myDebris[index]->GetViewHitBox()))
		{
			myDebris[index]->Update(aDeltaTime);
		}

		if (MT::Length(aCamera.GetTargetPosition() - myDebris[index]->GetPosition()) > aRenderWindow.getSize().x * 5.f)
		{
			delete myDebris[index];
			myDebris[index] = nullptr;
			myDebris[index] = myDebris.back();
			myDebris.pop_back();
		}
	}

	if (MT::Length(myOldPlayerPosition - myPlayerPosition) > myDistanceBetweenSpawn)
	{
		myOldPlayerPosition = myPlayerPosition;
		
		if (MT::Chance(50))
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

void Debris::Notify(GameEvent aEvent, float aX, float aY)
{
	if (aEvent == EVENT_PLAYER_NEW_POSITION)
	{
		myPlayerPosition.x = aX;
		myPlayerPosition.y = aX;
	}
}

void Debris::SpawnAsteroid(const Camera& aCamera, const sf::RenderWindow& aRenderWindow)
{
	
	float x = 0;
	float y = 0;

	while (x == 0 && y == 0)
	{
		x = sinf(static_cast<float>(rand()));
		y = sinf(static_cast<float>(rand()));
	}
	
	sf::Vector2f position(aCamera.GetCenter().x, aCamera.GetCenter().y);
	position.x += x * static_cast<float>(aCamera.GetDimensions().x);
	position.y += y * static_cast<float>(aCamera.GetDimensions().y);

	AsteroidSize spawnSize = static_cast<AsteroidSize>(rand() % static_cast<int>(AsteroidSize::count));
	
	Asteroid* spawned = new Asteroid();
	spawned->Init(spawnSize, position);

	while (aCamera.CanSee(spawned->GetViewHitBox()))
	{
		spawned->SetPosition(spawned->GetPosition() * 1.5f);
	}

	myDebris.push_back(spawned);
	
}
