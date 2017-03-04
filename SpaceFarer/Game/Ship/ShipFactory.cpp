#include "ShipFactory.h"
#include "..\..\TextureBank.h"

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

Ship* ShipFactory::BuildShip(ShipModel aType)
{
	Ship* newShip = new Ship(myShipTypes.Build(aType));
	newShip->Init();
	return newShip;
}

ShipFactory::ShipFactory()
{
}
