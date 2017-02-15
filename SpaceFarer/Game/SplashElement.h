#pragma once
#include "..\Engine\Drawable.h"

namespace sf
{
	class RenderWindow;
	class String;
}

class SplashElement
{
public:
	SplashElement();
	void		Init(const sf::String& aImage, float aTimeToShow = 3.0f, float aFadeTime = 2.0f);
	void		Update(float aDeltaTime);
	void		Render(sf::RenderWindow& aGameWindow);
	bool		IsFadedOut();
private:
	float		myTimer;
	float		myTimeBetweenFades;
	float		myTimeToShow;
	bool		myIsFadingIn;
	bool		myIsFadingOut;
	bool		myIsFadedOut;
	Drawable	myImage;
};