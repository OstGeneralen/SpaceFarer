#include "SpaceStationState.h"
#include "SFML\Window\Event.hpp"
#include "StateManger.h"

void SpaceStationState::Load(GameData aData)
{
	State::Load(aData);
	myText.SetString("In SpaceStation Press Space To Enter Space Again");
	myText.SetOriginToMiddle(true, true);
	myText.SetPosition({ static_cast<float>(myData.myGameWindow->getSize().x / 2), static_cast<float>(myData.myGameWindow->getSize().y / 2 )});
}

void SpaceStationState::Update(float aDeltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		StateManager::GetInstance().ChangeState(GameState::Flying, myData);
	}
}

void SpaceStationState::Render()
{
	myText.Render(*myData.myGameWindow);
}
