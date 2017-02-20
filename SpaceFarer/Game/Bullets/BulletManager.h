#pragma once
#include <vector>
#include "Projectile.h"
#include "..\..\Engine\Animation\Animation.h"
#include "..\..\Engine\Animation\AnimationFactory.h"

class Camera;

namespace sf
{
	class RenderWindow;
}

class BulletManager
{
public:
	static	BulletManager&		GetInstance();

	void						Init();
	void						AddPlayerBullet(Projectile* aProjectilePointer);
	void						AddEnemyBullet(Projectile* aProjectilePointer);
	void						RemovePlayerBullet(const int aIndex);
	void						RemoveEnemyBullet(const int aIndex);
	void						Update(const float aDT, Camera& aGameCamera);
	void						Render(sf::RenderWindow& aRenderWindow);

private:
	BulletManager();

	std::vector<Actor*>	myPlayerProjectiles;
	std::vector<Actor*>	myEnemyProjectiles;
	std::vector<Animation*> myExplosionAnimations;
};