#include "MenuState.h"
#include "SFML\Window\Event.hpp"
#include "StateManger.h"
#include "..\..\TextureBank.h"
#include "..\GUI\Cursor.h"

void MenuState::Load(GameData aData)
{
	State::Load(aData);

	myCamera = Camera(*myData.myGameWindow);

	void(MenuState::*startFunction)() = &MenuState::StartGame;
	myStartButton.Init(GET_TEXTURE("StartButton"), this, startFunction);

	myStartButton.SetPosition({ myData.myGameWindow->getSize().x / 2.f, myData.myGameWindow->getSize().y / 2.f });

	Cursor::GetInstance().AttatchObserver(&myStartButton);

	if (myData.myPlayer != nullptr)
	{
		delete myData.myPlayer;
		myData.myPlayer = nullptr;
	}
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
	myCamera.UseView(*myData.myGameWindow);
	myStartButton.Render(*myData.myGameWindow);

}

void MenuState::StartGame()
{
	StateManager::GetInstance().ChangeState(GameState::Flying, myData);
}
