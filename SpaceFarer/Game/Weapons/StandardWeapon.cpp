#include "StandardWeapon.h"
#include "..\..\TextureBank.h"
#include "..\..\Engine\MathTools.h"
#include <iostream>

StandardWeapon::StandardWeapon()
{
}


StandardWeapon::~StandardWeapon()
{
}

void StandardWeapon::SpecificUpdate(const float aDeltaTime)
{
	if (myShouldShoot)
	{
		Projectile* projectile = new Projectile();
		projectile->Init(GET_TEXTURE("shot"), true, myActor->GetTransform() * myOffset, 1, .8f);
		float rotation = MT::ToRadians(myActor->GetTransformable().getRotation());
		sf::Vector2f direction(cos(rotation), sin(rotation));
 		MT::Normalize(direction);

		projectile->SetVelocity(myActor->GetVelocity() + 1500.f * direction);
		if (myIsOwnedByPlayer)
		{
			BulletManager::GetInstance().AddPlayerBullet(projectile);
		}
		else
		{
			BulletManager::GetInstance().AddEnemyBullet(projectile);
		}

		ResetTimer();
	}
}