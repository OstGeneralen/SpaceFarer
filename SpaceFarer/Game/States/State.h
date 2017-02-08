#pragma once
#include "SFML\Graphics\RenderTexture.hpp"

enum class GameState
{
	Menu,
	Flying,
};


class State
{
public:
	virtual void Load(sf::RenderTexture* aGameWindow);
	virtual void Update(float aDeltaTime, GameState& aGameState) = 0;
	virtual void Render() = 0;
	virtual void WindowResize();
	bool GetIsLoaded() const;
protected:
	sf::RenderTexture* myGameWindow = nullptr;
	bool myIsLoaded = false;
};