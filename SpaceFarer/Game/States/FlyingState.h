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

class FlyingState : public State
{
public:
	void Load(sf::RenderWindow* aRenderWindow) override;
	void Update(float aDeltaTime, GameState& aGameState) override;
	void Render() override;
	void WindowResize() override;
private:
	void					HandleCollision(Actor& aActor1, Actor& aActor2);

	Background				myBackground;
	Player					myPlayer;
	Actor					myTempActor;
	std::vector<Actor*>		myActors;
	Gui						myGui;

	Camera					myGameCamera;
	Camera					myGuiCamera;
	Ship					myTempShip;
};