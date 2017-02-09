#include "StandardWeapon.h"
#include "Projectile.h"
#include "..\..\TextureBank.h"
#include "..\..\Engine\MathTools.h"

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
		projectile->Init(GET_TEXTURE("shot"), true, myActor->GetTransform() * myOffset, 1, 0.7f);
		float rotation = MT::ToRadians(myActor->GetTransformable().getRotation());
		sf::Vector2f direction(cos(rotation), sin(rotation));
 		MT::Normalize(direction);

		projectile->SetVelocity(myActor->GetVelocity() + 1500.f * direction);
		myActorListPtr->push_back(projectile);

		ResetTimer();
	}
}