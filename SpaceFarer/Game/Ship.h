#pragma once
#include "..\Engine\Actor.h"
#include "Observer\Subject.h"
#include "SFML\Graphics\Text.hpp"
#include "SFML\System\Vector2.hpp"

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
	void			SetUp();
	void			Update(float aDeltaTime) override;
protected:
	ShipFittings	myFittings;
	float			myCurrentFuel;
	sf::Vector2f	myDirection;
	bool			myInertiaEnabled;
	

};