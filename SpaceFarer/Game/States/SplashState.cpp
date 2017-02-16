#include "SplashState.h"
#include "StateManger.h"
#include "SFML\Window\Event.hpp"

void SplashState::Load(sf::RenderWindow * aGameWindow)
{
	State::Load(aGameWindow);

	myCurrentSplash = 0;

	float timeToShow = 3.f;
	float fadeTime = 3.f;

	mySplashElements.push_back(SplashElement());
	mySplashElements.back().Init("SFOLogo", timeToShow, fadeTime);

	mySplashElements.push_back(SplashElement());
	mySplashElements.back().Init("SFMLLogo", timeToShow, fadeTime);

	mySplashElements.push_back(SplashElement());
	mySplashElements.back().Init("GameLogo", timeToShow, fadeTime);
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
      	mySplashElements[myCurrentSplash].Skip();
	}

	mySplashElements[myCurrentSplash].Update(aDeltaTime);
}

void SplashState::Render()
{
	mySplashElements[myCurrentSplash].Render(*myGameWindow);
}


