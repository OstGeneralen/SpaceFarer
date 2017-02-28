#include "MenuState.h"
#include "SFML\Window\Event.hpp"
#include "StateManger.h"
#include "..\..\TextureBank.h"
#include "..\GUI\Cursor.h"

void MenuState::Load(sf::RenderWindow * aGameWindow)
{
	State::Load(aGameWindow);

	myCamera = Camera(*aGameWindow);

	void(MenuState::*startFunction)() = &MenuState::StartGame;
	myStartButton.Init(GET_TEXTURE("StartButton"), this, startFunction);

	myStartButton.SetPosition({ myGameWindow->getSize().x / 2.f, myGameWindow->getSize().y / 2.f });

	Cursor::GetInstance().AttatchObserver(&myStartButton);
}

void MenuState::Unload()
{
	Cursor::GetInstance().DetatchObserver(&myStartButton);
	myStartButton.Destroy();
}

void MenuState::Update(float aDeltaTime)
{
}

void MenuState::Render()
{
	myCamera.UseView(*myGameWindow);
	myStartButton.Render(*myGameWindow);

}

void MenuState::StartGame()
{
	StateManager::GetInstance().ChangeState(GameState::Flying, *myGameWindow);
}
