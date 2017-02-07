#include "ShipFactory.h"

ShipFactory & ShipFactory::GetInstance()
{
	static ShipFactory* instace = new ShipFactory();

	if (!instace->myIsCreated)
	{
		instace->myShipTypes.CreateBlueprints();
		instace->myIsCreated = true;
	}

	return *instace;
}

Ship ShipFactory::BuildShip(ShipModel aType)
{
	return Ship(myShipTypes.Build(aType));
}

ShipFactory::ShipFactory()
{
}
