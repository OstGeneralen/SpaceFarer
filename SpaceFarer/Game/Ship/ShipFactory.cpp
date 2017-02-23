#include "ShipFactory.h"

ShipFactory & ShipFactory::GetInstance()
{
	static ShipFactory* instace = new ShipFactory();

	if (!instace->myIsCreated)
	{
		instace->myIsCreated = true;
	}

	return *instace;
}

void ShipFactory::Init(const std::string & aJsonPath)
{
	myShipTypes.CreateBlueprints(aJsonPath);
}

Ship ShipFactory::BuildShip(ShipModel aType)
{
	return Ship(myShipTypes.Build(aType));
}

ShipFactory::ShipFactory()
{
}
