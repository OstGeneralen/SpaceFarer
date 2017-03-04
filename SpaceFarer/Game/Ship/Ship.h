#pragma once
#include "..\..\Engine\Actor.h"
#include "..\Observer\Subject.h"
#include "..\Weapons\Weapon.h"
#include "SFML\Graphics\Text.hpp"
#include "SFML\System\Vector2.hpp"
#include <vector>
#include "..\Weapons\WeaponFactory.h"
#include "..\GUI\HealthBar.h"

struct ShipFittings
{
	bool			myHasInertia = false;
	float			myFuelTank = 0;
	float			myFuelUsage = 0;
	float			myAcceleration = 0;
	float			myTurnSpeed = 0;
	float			myMaxHealth = 0;
	float			myCurrentHealth = 0;
	int				myValue = 0;
	float			myInertiaFactor = 0;
	float			myMass = 0;
	std::string		myName = "";
	WeaponTypes		myWeaponType;
};

class Ship : public Actor, public Subject
{
public:
	Ship() = default;
	Ship(ShipFittings* aFittings);	
	void				Init();
	void				SetUp(const bool aOwnedByPlayer = false);
	void				Stop();
	void				Update(float aDeltaTime) override;
	void				Render(sf::RenderWindow& aGameWindow) override;
	const std::string&	GetName() const;
	void				TakeDamage(float aDamage);
	bool				GetIsDead() const;
protected:
	void				DoMovement(float aDeltaTime);
	void				UpdateInertia(float aDeltaTime);
	ShipFittings*		myFittings;
	float				myCurrentFuel;
	sf::Vector2f		myDirection;
	sf::Vector2f		mySideDirection;
	bool				myInertiaEnabled;
	Weapon*				myWeapon;
	HealthBar			myHealthBar;

};