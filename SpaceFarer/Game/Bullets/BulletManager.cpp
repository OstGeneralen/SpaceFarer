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
	aProjectilePointer->GiveCollider(new CircleCollider(aProjectilePointer->GetPosition(), aProjectilePointer->GetRadius()));
	myPlayerProjectiles.push_back(aProjectilePointer);
}

void BulletManager::AddEnemyBullet(Projectile * aProjectilePointer)
{
	aProjectilePointer->GiveCollider(new CircleCollider(aProjectilePointer->GetPosition(), aProjectilePointer->GetRadius()));
	myEnemyProjectiles.push_back(aProjectilePointer);
}

void BulletManager::RemovePlayerBullet(const int aIndex)
{
	myExplosionAnimations.push_back(GET_ANIMATION("smallExplosion"));
	myExplosionAnimations.back()->Play(myPlayerProjectiles[aIndex]->GetPosition());

	delete myPlayerProjectiles[aIndex];
	myPlayerProjectiles[aIndex] = nullptr;
	myPlayerProjectiles[aIndex] = myPlayerProjectiles.back();
	myPlayerProjectiles.pop_back();
}

void BulletManager::RemoveEnemyBullet(const int aIndex)
{
	myExplosionAnimations.push_back(GET_ANIMATION("smallExplosion"));
	myExplosionAnimations.back()->Play(myPlayerProjectiles[aIndex]->GetPosition());

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

	// Updating explosions
	for (unsigned i = 0; i < myExplosionAnimations.size(); i++)
	{
		myExplosionAnimations[i]->Update(aDT);
	}
	for (int i = myExplosionAnimations.size() - 1; i >= 0; --i)
	{
		if (myExplosionAnimations[i]->IsDone())
		{
			DESTROY_ANIMATION(myExplosionAnimations[i]);
			myExplosionAnimations[i] = myExplosionAnimations.back();
			myExplosionAnimations.pop_back();
		}
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

	for (unsigned i = 0; i < myExplosionAnimations.size(); i++)
	{
		myExplosionAnimations[i]->Render(aRenderWindow);
	}
}

BulletManager::BulletManager()
{
}
