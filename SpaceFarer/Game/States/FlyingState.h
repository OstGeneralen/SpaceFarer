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

class FlyingState : public State
{
public:
	void Load(sf::RenderWindow* aRenderWindow) override;
	void LoadWithPosition(const sf::Vector2f& aPosition) override;
	void Unload() override;
	void Update(float aDeltaTime) override;
	void Render() override;
	void WindowResize() override;
private:
	Debris					myDebris;
	SpaceStation			mySpaceStation;

	Background				myBackground;
	Player					myPlayer;
	Actor					myTempActor;
	std::vector<Actor*>		myActors;
	Gui						myGui;

	Camera					myGameCamera;
	Camera					myGuiCamera;
	Ship					myTempShip;
};