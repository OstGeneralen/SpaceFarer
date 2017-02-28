#pragma once
#include "State.h"
#include "..\..\Engine\Camera.h"
#include "..\GUI\Button.h"

class MenuState : public State
{
public:
	void		Load(sf::RenderWindow* aGameWindow) override;
	void		Unload() override;
	void		Update(float aDeltaTime) override;
	void		Render() override;
private:
	void		StartGame();
	Button<MenuState> myStartButton;
	Camera		myCamera;

};