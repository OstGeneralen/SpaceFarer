#pragma once
#include "..\Engine\Actor.h"
#include "Observer\Subject.h"
#include "Ship\Ship.h"
#include "Weapons\StandardWeapon.h"
#include "Wallet.h"

class Player : public Entity, public Subject
{
public:
	Player();
	void			Update(float aDeltaTime);
	void			Render(sf::RenderWindow& aRenderWindow);
	void			GiveShip(Ship* aShip);
	void			SetTarget(const sf::Vector2f& aTargetPosition);
	Ship&			GetShip() const;
	Wallet&			GetWallet();
private:
	Wallet			myWallet;
	Ship*			myShip = nullptr;
};