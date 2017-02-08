#pragma once
#include "State.h"
#include "..\GUI\GuiText.h"

class MenuState : public State
{
public:
	void Load(sf::RenderWindow* aGameWindow) override;
	void Update(float aDeltaTime, GameState& aGameState) override;
	void Render() override;
private:
	GuiText myTempText;

};