#include "BulletManager.h"
#include <SFML\Graphics\RenderWindow.hpp>
#include "..\..\Engine\Camera.h"
#include "..\CollisionManager.h"

BulletManager & BulletManager::GetInstance()
{
	static BulletManager instance;
	return instance;
}

void BulletManager::Init()
{
	CollisionManager::GetInstance().SetPlayerBulletList(&myPlayerProjectiles);
	CollisionManager::GetInstance().SetEnemyBulletList(&myEnemyProjectiles);
}

void BulletManager::AddPlayerBullet(Projectile * aProjectilePointer)
{
	myPlayerProjectiles.push_back(aProjectilePointer);
}

void BulletManager::AddEnemyBullet(Projectile * aProjectilePointer)
{
	myEnemyProjectiles.push_back(aProjectilePointer);
}

void BulletManager::RemovePlayerBullet(const int aIndex)
{
	delete myPlayerProjectiles[aIndex];
	myPlayerProjectiles[aIndex] = nullptr;
	myPlayerProjectiles[aIndex] = myPlayerProjectiles.back();
	myPlayerProjectiles.pop_back();
}

void BulletManager::RemoveEnemyBullet(const int aIndex)
{
	delete myEnemyProjectiles[aIndex];
	myEnemyProjectiles[aIndex] = nullptr;
	myEnemyProjectiles[aIndex] = myEnemyProjectiles.back();
	myEnemyProjectiles.pop_back();
}

void BulletManager::Update(const float aDT, Camera& aGameCamera)
{
	// Deleting out of bounds projectiles spawned by player
	for (int i = myPlayerProjectiles.size() - 1; i > 0; --i)
	{
		if (!aGameCamera.CanSee(myPlayerProjectiles[i]->GetViewHitBox()))
		{
			RemovePlayerBullet(i);
		}
	}
	// Same for enemy-spawned
	for (int i = myEnemyProjectiles.size() - 1; i > 0; --i)
	{
		if (!aGameCamera.CanSee(myEnemyProjectiles[i]->GetViewHitBox()))
		{
			RemoveEnemyBullet(i);
		}
	}
	// Updating the rest
	for (unsigned i = 0; i < myPlayerProjectiles.size(); i++)
	{
		myPlayerProjectiles[i]->Update(aDT);
	}
	for (unsigned i = 0; i < myEnemyProjectiles.size(); i++)
	{
		myEnemyProjectiles[i]->Update(aDT);
	}
}

void BulletManager::Render(sf::RenderWindow & aRenderWindow)
{
	for (unsigned i = 0; i < myPlayerProjectiles.size(); ++i)
	{
		myPlayerProjectiles[i]->Render(aRenderWindow);
	}
	for (unsigned i = 0; i < myEnemyProjectiles.size(); ++i)
	{
		myEnemyProjectiles[i]->Render(aRenderWindow);
	}
}

BulletManager::BulletManager()
{
}
