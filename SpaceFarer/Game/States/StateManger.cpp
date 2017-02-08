#include "StateManger.h"
#include "SFML\Graphics\RenderWindow.hpp"
#include "FlyingState.h"
#include "MenuState.h"

StateManager & StateManager::GetInstance()
{
	static StateManager instance;

	return instance;
}

void StateManager::ChangeState(GameState aTo, sf::RenderWindow& aRenderWindow)
{
	for (unsigned int index = 0; index < myStates.size(); ++index)
	{
		if (myStates[index].myStateType == aTo)
		{
			myCurrentState = index;
			myStates[index].myState->Load(&aRenderWindow);
		}
	}
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

	AddState(GameState::Menu, new MenuState);
	AddState(GameState::Flying, new FlyingState);
}
