#pragma once
#include "State.h"
#include "..\GUI\GuiText.h"
#include "..\..\Engine\Camera.h"
class MenuState : public State
{
public:
	void Load(sf::RenderWindow* aGameWindow) override;
	void Update(float aDeltaTime) override;
	void Render() override;
private:
	GuiText myTempText;
	Camera myCamera;

};