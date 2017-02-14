#include "StateManger.h"
#include "SFML\Graphics\RenderWindow.hpp"
#include "FlyingState.h"
#include "MenuState.h"
#include "SpaceStationState.h"
#include "SplashState.h"

StateManager & StateManager::GetInstance()
{
	static StateManager instance;

	return instance;
}

void StateManager::ChangeState(GameState aTo, sf::RenderWindow& aRenderWindow)
{
	if (myCurrentState != -1)
	{
		myStates[myCurrentState].myState->Unload();
	}

	for (unsigned int index = 0; index < myStates.size(); ++index)
	{
		if (myStates[index].myStateType == aTo)
		{
			myCurrentState = index;
			myStates[index].myState->Load(&aRenderWindow);
		}
	}
}

void StateManager::ChangeStateWithPosition(GameState aTo, sf::RenderWindow & aRenderWindow, const sf::Vector2f & aPosition)
{
	ChangeState(aTo, aRenderWindow);
	myStates[myCurrentState].myState->LoadWithPosition(aPosition);
}

void StateManager::WindowResize()
{
	myStates[myCurrentState].myState->WindowResize();
}

void StateManager::Update(float aDeltaTime)
{
	assert(myCurrentState != -1 && "No game state is set");
	myStates[myCurrentState].myState->Update(aDeltaTime);
}

void StateManager::Render()
{
	assert(myCurrentState != -1 && "No game state is set");
	myStates[myCurrentState].myState->Render();
}

void StateManager::AddState(GameState aStateType, State * aState)
{
	StateData data;
	data.myState = aState;
	data.myStateType = aStateType;
	myStates.push_back(data);
}

StateManager::StateManager()
{
	myCurrentState = -1;

	AddState(GameState::Splash, new SplashState);
	AddState(GameState::Menu, new MenuState);
	AddState(GameState::Flying, new FlyingState);
	AddState(GameState::SpaceStation, new SpaceStationState);
}
