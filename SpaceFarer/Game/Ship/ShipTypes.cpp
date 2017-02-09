#include "ShipTypes.h"

ShipTypes::ShipTypes()
{
}

void ShipTypes::CreateBlueprints()
{
	ShipFittings& current = myShipModels[static_cast<int>(ShipModel::Debug)];
	current.myHasInertia = true;
	current.myInertiaFactor = 10;
	current.myFuelTank = 1000;
	current.myFuelUsage = 0;
	current.myAcceleration = 500;
	current.myTurnSpeed = 200;
	current.myValue = 1000000;
	current.myWeaponType = WeaponTypes::BurstFire;
	current.myName = "Debug Ship";
}

ShipFittings ShipTypes::Build(ShipModel aShipModel)
{
	return myShipModels[static_cast<int>(aShipModel)];
}
