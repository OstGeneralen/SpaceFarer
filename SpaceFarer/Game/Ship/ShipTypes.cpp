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
		current.myMaxHealth =		specificShipData["maxHealth"].get<int>();
		current.myValue =			specificShipData["value"].get<int>();
		current.myTurnSpeed =		specificShipData["turnSpeed"].get<int>();
		current.myAcceleration =	specificShipData["acceleration"].get<int>();
		current.myFuelUsage =		specificShipData["fuelUsage"].get<int>();
		current.myFuelTank =		specificShipData["fuelTankCapacity"].get<int>();
		current.myInertiaFactor =	specificShipData["inertiaFactor"].get<int>();
		current.myHasInertia =		specificShipData["hasInertia"].get<bool>();
		current.myWeaponType =		static_cast<WeaponTypes>(specificShipData["weaponType"].get<int>());
		
		current.myCurrentHealth = current.myMaxHealth;
	}
}

ShipFittings ShipTypes::Build(ShipModel aShipModel)
{
	return myShipModels[static_cast<int>(aShipModel)];
}
