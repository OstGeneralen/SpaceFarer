#pragma once
#include "State.h"
#include "..\GUI\GuiText.h"

class SpaceStationState : public State
{
public:
	void Load(sf::RenderWindow* aGameWindow) override;
	void Update(float aDeltaTime) override;
	void Render() override;
private:
	GuiText myText;


};