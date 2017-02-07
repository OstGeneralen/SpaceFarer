#pragma once
#include "Ship.h"
#include "ShipTypes.h"

class ShipFactory
{
public:
	static ShipFactory& GetInstance();
	Ship BuildShip(ShipModel aType);
private:
	ShipFactory();
	ShipTypes myShipTypes;
	bool myIsCreated = false;
};