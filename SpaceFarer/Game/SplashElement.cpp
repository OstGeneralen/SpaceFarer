#include "SplashElement.h"
#include "SFML\Graphics\Text.hpp"
#include "SFML\Graphics\RenderWindow.hpp"
#include "..\TextureBank.h"

SplashElement::SplashElement()
{
	myIsFadedOut = false;
	myIsFadingOut = false;
}

void SplashElement::Init(const sf::String & aImage, float aTimeToShow, float aFadeTime)
{
	myImage.Init(TextureBank::GetInstance().GetTexture(aImage));
	myImage.SetOrigin({myImage.GetSpriteDimensions().x / 2, myImage.GetSpriteDimensions().y / 2});
	myImage.SetOpacity(0);
	myIsFadingIn = true;
	myTimeToShow = aTimeToShow;
	myTimer = 0;
	myTimeBetweenFades = aFadeTime / 255.f;
}

void SplashElement::Update(float aDeltaTime)
{
	if (myIsFadingIn)
	{
		if (myImage.GetOpacity() < 255)
		{
			myTimer += aDeltaTime;

			if (myTimer >= myTimeBetweenFades)
			{
				myTimer = 0;
				myImage.SetOpacity(myImage.GetOpacity() + 1);
			}
			return;
		}

		myTimer = 0;
		myIsFadingIn = false;
	}
	else if (myIsFadingOut)
	{
		if (myImage.GetOpacity() > 0)
		{
			myTimer += aDeltaTime;

			if (myTimer >= myTimeBetweenFades)
			{
				myTimer = 0;
				myImage.SetOpacity(myImage.GetOpacity() - 1);
			}
			return;
		}

		myIsFadedOut = true;
	}
	else
	{
		myTimer += aDeltaTime;
		if (myTimer >= myTimeToShow)
		{
			myTimer = 0;
			myIsFadingOut = true;
		}
	}
}

void SplashElement::Render(sf::RenderWindow & aGameWindow)
{
	myImage.SetPosition({ static_cast<float>(aGameWindow.getSize().x) / 2.f, static_cast<float>(aGameWindow.getSize().y) / 2.f });
	myImage.Render(aGameWindow);
}

bool SplashElement::IsFadedOut()
{
	return myIsFadedOut;
}
