#pragma once
#include <vector>
#include "Projectile.h"

class Camera;

namespace sf
{
	class RenderWindow;
}

class BulletManager
{
public:
	static	BulletManager&		GetInstance();

	void						AddBullet(Projectile* aProjectilePointer);
	void						Update(const float aDT, Camera& aGameCamera);
	void						Render(sf::RenderWindow& aRenderWindow);

private:
	BulletManager();

	std::vector<Projectile*>	myProjectiles;
};