#include "BurstFireWeapon.h"
#include "..\Bullets\Projectile.h"
#include "..\..\TextureBank.h"
#include "..\..\Engine\MathTools.h"

BurstFireWeapon::BurstFireWeapon()
{
	myIndividualShotTimer = 0;
	myIndividualShotDelay = 0.1f;
	myShotsPerBurst = 3;
	myShotCount = 0;
}


BurstFireWeapon::~BurstFireWeapon()
{
}

void BurstFireWeapon::SpecificUpdate(const float aDeltaTime)
{
	if (myShouldShoot)
	{
		myIndividualShotTimer += aDeltaTime;
		if (myIndividualShotTimer >= myIndividualShotDelay)
		{
			myIndividualShotTimer -= myIndividualShotDelay;

			Projectile* projectile = new Projectile();
			projectile->Init(GET_TEXTURE("shot"), true, myActor->GetTransform() * myOffset, 1, .8f);
			float rotation = MT::ToRadians(myActor->GetTransformable().getRotation());
			sf::Vector2f direction(cos(rotation), sin(rotation));
			MT::Normalize(direction);

			projectile->SetVelocity(myActor->GetVelocity() + 1500.f * direction);
			BulletManager::GetInstance().AddBullet(projectile);

			++myShotCount;
		}
		if (myShotCount >= myShotsPerBurst)
		{
			myShotCount = 0;
			myIndividualShotTimer = 0;
			ResetTimer();
		}
	}
}
