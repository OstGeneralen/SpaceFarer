#pragma once
#include "State.h"
#include <vector>
#include <assert.h>
#include "..\GameData.h"

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
	static StateManager&	GetInstance();
	void					ChangeState(GameState aTo, GameData aData);
	void					WindowResize();
	void					Update(float aDeltaTime);
	void					Render();
private:
	StateManager();
	void					AddState(GameState aStateType, State* aState);
	int						myCurrentState;
	std::vector<StateData>	myStates;
};