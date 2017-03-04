#include "ShipTypes.h"
#include "..\..\Engine\json.hpp"
#include <fstream>

ShipTypes::ShipTypes()
{
}

void ShipTypes::CreateBlueprints(const std::string & aJsonPath)
{
	jsonWrapper::json jsonData;

	std::ifstream instream(aJsonPath);
	jsonData << instream;

	for (unsigned i = 0; i < static_cast<int>(ShipModel::Count); ++i)
	{
		std::string iAsCString = std::to_string(i);
		jsonWrapper::json specificShipData = jsonData[iAsCString.c_str()];
		

		ShipFittings& current =		myShipModels[i];
		current.myName =			specificShipData["name"].get<std::string>();
		current.myMaxHealth =		specificShipData["maxHealth"];
		current.myValue =			specificShipData["value"];
		current.myTurnSpeed =		specificShipData["turnSpeed"];
		current.myAcceleration =	specificShipData["acceleration"];
		current.myFuelUsage =		specificShipData["fuelUsage"];
		current.myFuelTank =		specificShipData["fuelTankCapacity"];
		current.myMass =			specificShipData["mass"];
		current.myInertiaFactor =	specificShipData["inertiaFactor"];
		current.myHasInertia =		specificShipData["hasInertia"];
		current.myWeaponType =		static_cast<WeaponTypes>(specificShipData["weaponType"].get<int>());
		
		current.myCurrentHealth = current.myMaxHealth;
	}
}

ShipFittings* ShipTypes::Build(ShipModel aShipModel)
{
	return &myShipModels[static_cast<int>(aShipModel)];
}
