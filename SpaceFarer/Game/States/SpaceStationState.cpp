#include "SpaceStationState.h"
#include "SFML\Window\Event.hpp"
#include "StateManger.h"
#include "..\..\TextureBank.h"
#include "..\GUI\Cursor.h"

void SpaceStationState::Load(GameData aData)
{
	State::Load(aData);

	void(SpaceStationState::*function)();
	
	function = &SpaceStationState::Exit;
	myExitButton.Init(GET_TEXTURE("ExitSpaceStationButton"), this, function);

	function = &SpaceStationState::RepairShip;
	myRepairButton.Init(GET_TEXTURE("RepairShipButton"), this, function);

	Cursor::GetInstance().AttatchObserver(&myExitButton);
	Cursor::GetInstance().AttatchObserver(&myRepairButton);

	float winW = static_cast<float>(myData.myGameWindow->getSize().x);
	float winH = static_cast<float>(myData.myGameWindow->getSize().y);
	myRepairButton.SetPosition({ winW * 0.25f, winH / 2 });
	myExitButton.SetPosition({ winW * 0.75f, winH / 2 });
}

void SpaceStationState::Unload()
{
	myRepairButton.Destroy();
	myExitButton.Destroy();
}

void SpaceStationState::Update(float aDeltaTime)
{

}

void SpaceStationState::Render()
{
	myExitButton.Render(*myData.myGameWindow);
	myRepairButton.Render(*myData.myGameWindow);
}

void SpaceStationState::Exit()
{
	StateManager::GetInstance().ChangeState(GameState::Flying, myData);
}

void SpaceStationState::RepairShip()
{
	myData.myPlayer->GetShip()->Repair();
}
