#include "BulletManager.h"
#include <SFML\Graphics\RenderWindow.hpp>
#include "..\..\Engine\Camera.h"

BulletManager & BulletManager::GetInstance()
{
	static BulletManager instance;
	return instance;
}

void BulletManager::AddBullet(Projectile * aProjectilePointer)
{
	myProjectiles.push_back(aProjectilePointer);
}

void BulletManager::Update(const float aDT, Camera& aGameCamera)
{
	for (int i = myProjectiles.size() - 1; i > 0; --i)
	{
		if (!aGameCamera.CanSee(myProjectiles[i]->GetViewHitBox()))
		{
			delete myProjectiles[i];
			myProjectiles[i] = nullptr;
			myProjectiles[i] = myProjectiles.back();
			myProjectiles.pop_back();
		}
	}

	for (unsigned i = 0; i < myProjectiles.size(); i++)
	{
		myProjectiles[i]->Update(aDT);
	}
}

void BulletManager::Render(sf::RenderWindow & aRenderWindow)
{
	for (unsigned i = 0; i < myProjectiles.size(); ++i)
	{
		myProjectiles[i]->Render(aRenderWindow);
	}
}

BulletManager::BulletManager()
{
}
