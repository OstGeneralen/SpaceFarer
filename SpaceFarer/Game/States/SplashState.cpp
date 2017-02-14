#include "SplashState.h"
#include "StateManger.h"

void SplashState::Load(sf::RenderWindow * aGameWindow)
{
	State::Load(aGameWindow);

	myCurrentSplash = 0;

	mySplashElements.push_back(SplashElement());
	mySplashElements.back().Init("SFOLogo");

	mySplashElements.push_back(SplashElement());
	mySplashElements.back().Init("SFMLLogo");
}

void SplashState::Update(float aDeltaTime)
{
	if (mySplashElements[myCurrentSplash].IsFadedOut())
	{
		myCurrentSplash++;
		if (myCurrentSplash == mySplashElements.size())
		{
			StateManager::GetInstance().ChangeState(GameState::Menu, *myGameWindow);
			return;
		}
	}

	mySplashElements[myCurrentSplash].Update(aDeltaTime);
}

void SplashState::Render()
{
	mySplashElements[myCurrentSplash].Render(*myGameWindow);
}


