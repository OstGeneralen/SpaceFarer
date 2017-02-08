#include "ShipTypes.h"

ShipTypes::ShipTypes()
{
}

void ShipTypes::CreateBlueprints()
{
	ShipFittings* current = &myShipModels[static_cast<int>(ShipModel::Debug)];
	current->myHasInertia = true;
	current->myInertiaFactor = 10;
	current->myFuelTank = 1000;
	current->myFuelUsage = 0;
	current->myAcceleration = 500;
	current->myTurnSpeed = 100;
	current->myValue = 1000000;
	current->myName = "Debug Ship";

	current = &myShipModels[static_cast<int>(ShipModel::Standard)];
	current->myHasInertia = true;
	current->myInertiaFactor = 2;
	current->myFuelTank = 1000;
	current->myFuelUsage = 2;
	current->myAcceleration = 100;
	current->myTurnSpeed = 75;
	current->myValue = 100;
	current->myName = "Starter Ship";

	
}

ShipFittings ShipTypes::Build(ShipModel aShipModel)
{
	return myShipModels[static_cast<int>(aShipModel)];
}
