#pragma once
#include <array>
#include "Ship.h"

enum class ShipModel
{
	Debug,
	Standard,
	Speeder,
	Cargo,
	Count,
};

class ShipTypes
{
public:
	ShipTypes();
	void															CreateBlueprints(const std::string& aJsonPath);
	ShipFittings*													Build(ShipModel aShipModel);
private:
	std::array<ShipFittings, static_cast<int>(ShipModel::Count)>	myShipModels;

};