#include "MenuState.h"
#include "SFML\Window\Event.hpp"
#include "StateManger.h"

void MenuState::Load(sf::RenderWindow * aGameWindow)
{
	State::Load(aGameWindow);

	myCamera = Camera(*aGameWindow);

	myTempText.SetString("Press Space to enter Space");
	myTempText.SetOriginToMiddle(true, true);
	myTempText.SetPosition({ static_cast<float>(myGameWindow->getSize().x / 2), static_cast<float>(myGameWindow->getSize().y / 2 )});

}

void MenuState::Update(float aDeltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		StateManager::GetInstance().ChangeState(GameState::Flying, *myGameWindow);
	}
}

void MenuState::Render()
{
	myCamera.UseView(*myGameWindow);
	
	myTempText.Render(*myGameWindow);
}
