#include "Animation.h"
#include "SFML\Graphics\Texture.hpp"
#include "SFML\Graphics\Rect.hpp"
#include "SFML\Graphics\RenderWindow.hpp"



Animation::Animation(sf::Texture * aTexture)
{
	myTexture = aTexture;
	myCurrentSprite.setTexture(*aTexture);
}

void Animation::AddFrame(const sf::IntRect& aRect, float aTime)
{
	Frame newFrame;
	newFrame.myRect = aRect;
	newFrame.myTime = aTime;
	myFrames.push_back(newFrame);
}

void Animation::Play(bool aIsRepeating)
{
	myIsPlaying = true;
	myIsRepeat = aIsRepeating;
	myCurrentFrame = 0;
	myTimer = 0;

	myCurrentSprite.setTextureRect(myFrames[0].myRect);
}

void Animation::Update(float aDeltaTime)
{
	if (myIsPlaying)
	{
		myTimer += aDeltaTime;

		if (myTimer >= myFrames[myCurrentFrame].myTime)
		{
			ChangeFrame();
		}
	}
}

void Animation::Render(sf::RenderWindow & aGameWindow)
{
	if (myIsPlaying)
	{
		aGameWindow.draw(myCurrentSprite);
	}
}

void Animation::ChangeFrame()
{
	myTimer = 0;
	myCurrentFrame++;

	if (myCurrentFrame >= myFrames.size())
	{
		if (myIsRepeat)
		{
			myCurrentFrame = 0;
		}
		else
		{
			myIsPlaying = false;
		}
	}
	
	if(myIsPlaying)
	{
		myCurrentSprite.setTextureRect(myFrames[myCurrentFrame].myRect);
	}
}
