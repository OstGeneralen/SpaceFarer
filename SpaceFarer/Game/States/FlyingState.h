#pragma once
#include "State.h"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "..\..\Game\Player.h"
#include "..\..\Engine\DebugTools.h"
#include "..\..\Engine\Camera.h"
#include "..\..\Game\Asteroid.h"
#include <vector>
#include "..\Background.h"
#include "..\GUI\Gui.h"
#include "..\Ship\Ship.h"
#include "..\Station\SpaceStation.h"
#include "..\Debris.h"
#include "..\Observer\Observer.h"

class FlyingState : public State, public Observer
{
public:
	void					Load(GameData aData) override;
	void					Unload() override;
	void					Update(float aDeltaTime) override;
	void					Render() override;
	void					WindowResize() override;
	void					Notify(GameEvent aEvent, const sf::String& aString) override;
private:
	
	void					LoadPlayer();

	Debris					myDebris;
	SpaceStation			mySpaceStation;

	Background				myBackground;
	Actor					myTempActor;
	Gui						myGui;

	Camera					myGameCamera;
	Camera					myGuiCamera;
	Ship					myTempShip;
};