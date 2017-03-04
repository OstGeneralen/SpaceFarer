#pragma once
#include "State.h"
#include "..\GUI\Button.h"

class SpaceStationState : public State
{
public:
	void		Load(GameData aData) override;
	void		Unload() override;
	void		Update(float aDeltaTime) override;
	void		Render() override;
private:
	void Exit();
	void RepairShip();
	Button<SpaceStationState>	myExitButton;
	Button<SpaceStationState>	myRepairButton;


};