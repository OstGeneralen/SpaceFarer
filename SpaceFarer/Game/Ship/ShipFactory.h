#pragma once
#include "Ship.h"
#include "ShipTypes.h"

class ShipFactory
{
public:
	static ShipFactory&		GetInstance();
	void					Init(const std::string& aJsonPath);
	Ship					BuildShip(ShipModel aType);
private:
	ShipFactory();
	ShipTypes				myShipTypes;
	bool					myIsCreated = false;
};