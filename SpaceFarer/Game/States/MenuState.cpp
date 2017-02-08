#include "MenuState.h"
#include "SFML\Window\Event.hpp"

void MenuState::Load(sf::RenderTexture * aGameWindow)
{
	State::Load(aGameWindow);

	myTempText.SetString("Press Space to enter Space");
	myTempText.SetOriginToMiddle(true, true);
	myTempText.SetPosition({ static_cast<float>(myGameWindow->getSize().x / 2), static_cast<float>(myGameWindow->getSize().y / 2 )});

}

void MenuState::Update(float aDeltaTime, GameState& aGameState)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		aGameState = GameState::Flying;
	}
}

void MenuState::Render()
{
	myTempText.Render(*myGameWindow);
}
