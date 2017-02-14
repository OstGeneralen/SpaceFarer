#pragma once
#include "State.h"
#include <vector>
#include "..\SplashElement.h"

class SplashState : public State
{
public:
	void Load(sf::RenderWindow* aGameWindow) override;
	void Update(float aDeltaTime) override;
	void Render() override;
private:
	unsigned int myCurrentSplash;
	std::vector<SplashElement> mySplashElements;
};