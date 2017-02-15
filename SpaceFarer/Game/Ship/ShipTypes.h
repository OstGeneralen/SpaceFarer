#pragma once
#include <array>
#include "Ship.h"

enum class ShipModel
{
	Debug,
	Standard,
	Count,
};

class ShipTypes
{
public:
	ShipTypes();
	void															CreateBlueprints();
	ShipFittings													Build(ShipModel aShipModel);
private:
	std::array<ShipFittings, static_cast<int>(ShipModel::Count)>	myShipModels;

};