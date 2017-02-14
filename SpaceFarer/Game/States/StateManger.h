#pragma once
#include "State.h"
#include <vector>
#include <assert.h>

enum class GameState
{
	Splash,
	Menu,
	Flying,
	SpaceStation,
};

struct StateData
{
	GameState myStateType;
	State* myState;
};

namespace sf
{
	class RenderWindow;
}

class StateManager
{
public:
	static StateManager& GetInstance();
	void ChangeState(GameState aTo, sf::RenderWindow& aRenderWindow);
	void ChangeStateWithPosition(GameState aTo, sf::RenderWindow& aRenderWindow, const sf::Vector2f& aPosition = { 0,0 });
	void WindowResize();
	void Update(float aDeltaTime);
	void Render();
private:
	void AddState(GameState aStateType, State* aState);
	StateManager();
	int myCurrentState;
	std::vector<StateData> myStates;
};