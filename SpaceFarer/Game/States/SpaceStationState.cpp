#include "SpaceStationState.h"
#include "SFML\Window\Event.hpp"
#include "StateManger.h"

void SpaceStationState::Load(sf::RenderWindow * aGameWindow)
{
	State::Load(aGameWindow);
	myText.SetString("In SpaceStation Press Space To Enter Space Again");
	myText.SetOriginToMiddle(true, true);
	myText.SetPosition({ static_cast<float>(myGameWindow->getSize().x / 2), static_cast<float>(myGameWindow->getSize().y / 2 )});
}

void SpaceStationState::Update(float aDeltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		StateManager::GetInstance().ChangeStateWithPosition(GameState::Flying, *myGameWindow, myLoadedPosition);
	}
}

void SpaceStationState::Render()
{
	myText.Render(*myGameWindow);
}
