#include "CollisionManager.h"
#include "..\Engine\MathTools.h"
#include "..\Engine\Camera.h"
#include <assert.h>


CollisionManager & CollisionManager::GetInstance()
{
	static CollisionManager instance;
	return instance;
}

void CollisionManager::SetPlayer(Player* aPlayer)
{
	myPlayerPtr = aPlayer;
}

void CollisionManager::SetDebrisList(std::vector<Actor*>* aDebrisList)
{
	myDebrisListPtr = aDebrisList;
}

void CollisionManager::SetEnemyBulletList(std::vector<Actor*>* aEnemyBulletList)
{
	myEnemyBulletListPtr = aEnemyBulletList;
}

void CollisionManager::SetPlayerBulletList(std::vector<Actor*>* aPlayerBulletList)
{
	myPlayerBulletListPtr = aPlayerBulletList;
}

void CollisionManager::SetEnemyList(std::vector<Actor*>* aEnemyList)
{
	myEnemyListPtr = aEnemyList;
}

void CollisionManager::Update(const Camera& aCamera)
{
	for (unsigned i = 0; i < myDebrisListPtr->size(); i++)
	{
		// Collision with self
		for (unsigned j = 0; j < myDebrisListPtr->size(); j++)
		{
			if (i != j && (aCamera.CanSee(myDebrisListPtr->at(i)->GetViewHitBox()) || aCamera.CanSee(myDebrisListPtr->at(j)->GetViewHitBox())))
			{
				if (myDebrisListPtr->at(i)->CheckIfColliding(*myDebrisListPtr->at(j)))
				{
					HandleCollision(myDebrisListPtr->at(i), myDebrisListPtr->at(j));
				}
			}
		}

		// Collision with player
		HandleCollision(myDebrisListPtr->at(i), myPlayerPtr->GetShip());

		// Collision with player bullets
		for (unsigned j = 0; j < myPlayerBulletListPtr->size(); j++)
		{
			if (myDebrisListPtr->at(i)->CheckIfColliding(*myPlayerBulletListPtr->at(j)))
			{
				HandleCollision(myDebrisListPtr->at(i), myPlayerBulletListPtr->at(j));
				BulletManager::GetInstance().RemovePlayerBullet(j);
			}
		}
	}
}

CollisionManager::CollisionManager()
{
}

void CollisionManager::HandleCollision(Actor* aActorOne, Actor* aActorTwo)
{
	if (aActorOne->CheckIfColliding(*aActorTwo))
	{
		sf::Vector2f normal = aActorTwo->GetPosition() - aActorOne->GetPosition();
		MT::Normalize(normal);
		sf::Vector2f relativeVel = aActorTwo->GetVelocity() - aActorOne->GetVelocity();
		float velocityScalar = MT::Dot(relativeVel, normal);

		if (velocityScalar > 0)
			return;

		float e = MT::Min(aActorOne->GetRestitution(), aActorTwo->GetRestitution());

		float j = -(1 + e) * velocityScalar;
		j /= ((1.f / aActorOne->GetMass()) + (1.f / aActorTwo->GetMass()));

		//normal *= velocityScalar;
		sf::Vector2f impulse = j * normal;
		aActorOne->ChangeVelocity(-1.f / (aActorOne->GetMass()) * impulse);
		aActorTwo->ChangeVelocity(1.f / (aActorTwo->GetMass()) * impulse);

		if (aActorTwo == myPlayerPtr->GetShip())
		{
			float damageToTake = 0;
			damageToTake -= velocityScalar * 0.025f;
			myPlayerPtr->GetShip()->TakeDamage(damageToTake);
		}
	}
}
