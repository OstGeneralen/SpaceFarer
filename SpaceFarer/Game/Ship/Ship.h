#pragma once
#include "..\..\Engine\Actor.h"
#include "..\Observer\Subject.h"
#include "SFML\Graphics\Text.hpp"
#include "SFML\System\Vector2.hpp"
#include <vector>

struct ShipFittings
{
	bool			myHasInertia = false;
	float			myFuelTank = 0;
	float			myFuelUsage = 0;
	float			myAcceleration = 0;
	float			myTurnSpeed = 0;
	int				myValue = 0;
	float			myInertiaFactor = 0;
	sf::String		myName = "";
};

class Ship : public Actor, public Subject
{
public:
	Ship() = default;
	Ship(ShipFittings aFittings);	
	void				SetUp();
	void				Update(float aDeltaTime) override;
	float				GetRotation() const;
	const sf::String&	GetName() const;
protected:
	void				DoMovement(float aDeltaTime);
	void				UpdateInertia(float aDeltaTime);
	ShipFittings		myFittings;
	float				myCurrentFuel;
	sf::Vector2f		myDirection;
	sf::Vector2f		mySideDirection;
	bool				myInertiaEnabled;
	

};