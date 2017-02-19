#pragma once
#include <vector>
#include "..\Engine\Actor.h"
#include "..\Game\Player.h"

class Camera;

class CollisionManager
{
public:
	static	CollisionManager&		GetInstance();
	void							SetPlayer(Player* aPlayer);
	void							SetDebrisList(std::vector<Actor*>* aDebrisList);
	void							SetEnemyBulletList(std::vector<Actor*>* aEnemyBulletList);
	void							SetPlayerBulletList(std::vector<Actor*>* aPlayerBulletList);
	/* NOT DONE */	void							SetEnemyList(std::vector<Actor*>* aEnemyList);
	void							Update(const Camera& aCamera);

private:
	CollisionManager();
	void							HandleCollision(Actor* aActorOne, Actor* aActorTwo);

	Player*							myPlayerPtr;
	std::vector<Actor*>*			myDebrisListPtr;
	std::vector<Actor*>*			myEnemyListPtr;
	std::vector<Actor*>*			myEnemyBulletListPtr;
	std::vector<Actor*>*			myPlayerBulletListPtr;
};

