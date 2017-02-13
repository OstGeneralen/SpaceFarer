#include "Background.h"
#include "SFML\Graphics\RenderWindow.hpp"
#include "..\TextureBank.h"
#include "..\Engine\MathTools.h"
#include <assert.h>
#include "..\Engine\Camera.h"

Background::Background()
{
}

void Background::CreateBackground(const sf::RenderWindow & aRenderWindow)
{
	/*
	myLayerOneSprite.setTextureRect({ 0,0,128,128 });
	myLayerTwoSprite.setTextureRect({ 128,0,128,128 });
	myLayerThreeSprite.setTextureRect({ 256, 0, 128,128 });
	myLayerOneSprite.setTexture(*GET_TEXTURE("smallStar"));
	myLayerTwoSprite.setTexture(*GET_TEXTURE("smallStar"));
	myLayerThreeSprite.setTexture(*GET_TEXTURE("smallStar"));

	myRenderPositions.clear();

	int windowW = aRenderWindow.getSize().x;
	int windowH = aRenderWindow.getSize().y;
	int cameraX = static_cast<int>(aRenderWindow.getView().getCenter().x);
	int cameraY = static_cast<int>(aRenderWindow.getView().getCenter().y);

	int startX = -windowW / 2 - 128;
	int staryY = -windowH / 2 - 128;
	int endX = windowW / 2;
	int endY = windowH / 2;

	for (int y = staryY; y < endY + 128; y += 128)
	{
		for (int x = startX; x < endX + 128; x += 128)
		{
			myRenderPositions.push_back({ static_cast<float>(x), static_cast<float>(y) });
		}
	}
	*/
	mySmallStarTexture = GET_TEXTURE("smallStar");
	myLastRenderPosition = aRenderWindow.getView().getCenter();
	myUpdateRadius = 1000;
}

void Background::Render(sf::RenderWindow & aRenderWindow, Camera& aGameCamera)
{ 
	int windowW = aRenderWindow.getSize().x;
	int windowH = aRenderWindow.getSize().y;
	int cameraX = static_cast<int>(aRenderWindow.getView().getCenter().x);
	int cameraY = static_cast<int>(aRenderWindow.getView().getCenter().y);
	/*
	for (unsigned int index = 0; index < myRenderPositions.size(); ++index)
	{
		
		
		if (myRenderPositions[index].x <= cameraX - (windowW / 2) - 256)
		{
			myRenderPositions[index].x = cameraX + windowW / 2;
		}
		else if (myRenderPositions[index].x >= ((cameraX + (windowW / 2)) + 128))
		{
			myRenderPositions[index].x = cameraX - (windowW / 2) - 128;
		}

		if (myRenderPositions[index].y <= cameraY - (windowH / 2) - 256)
		{
			myRenderPositions[index].y = cameraY + windowH / 2;
		}
		else if (myRenderPositions[index].y >= ((cameraY + (windowH / 2)) + 128))
		{
			myRenderPositions[index].y = cameraY - (windowH / 2) - 128;
		}
		

		myLayerOneSprite.setPosition(myRenderPositions[index]);
		aRenderWindow.draw(myLayerOneSprite);
	}
	*/

	if (MT::Length(sf::Vector2f(static_cast<float>(cameraX), static_cast<float>(cameraY)) - myLastRenderPosition) > myUpdateRadius / 2)
	{
		myLastRenderPosition = sf::Vector2f(cameraX, cameraY);
		UpdateStars(aGameCamera);
	}

	sf::Sprite renderingSprite;
	for (unsigned i = 0; i < myScenery.size(); ++i)
	{
		switch (myScenery[i].myType)
		{
		case SceneryType::SmallStar:
			renderingSprite.setTexture(*mySmallStarTexture);
			break;
		case SceneryType::Planet:
			renderingSprite.setTexture(*GET_TEXTURE("smallStar"));
			break;
		default:
			assert(false && "Non-existing type :D");
			break;
		}
		renderingSprite.setOrigin(0.5f, 0.5f);
		renderingSprite.setScale(myScenery[i].myScale);

		sf::Vector2f posInCameraSpace = sf::Vector2f(myScenery[i].myPosition.x, myScenery[i].myPosition.y) + sf::Vector2f(cameraX, cameraY);
		posInCameraSpace.x /= -myScenery[i].myPosition.z;
		posInCameraSpace.y /= -myScenery[i].myPosition.z;

		posInCameraSpace += sf::Vector2f(cameraX, cameraY);
		renderingSprite.setPosition(posInCameraSpace);
		renderingSprite.setRotation(myScenery[i].myRotation);
		if (aGameCamera.CanSee(posInCameraSpace))
		{
			aRenderWindow.draw(renderingSprite);
		}
	}
}

void Background::UpdateStars(const Camera& aGameCamera)
{
	//Remove stars outside the screen
	for (int i = myScenery.size() - 1; i >= 0; --i)
	{
		sf::Vector2f posInCameraSpace = sf::Vector2f(myScenery[i].myPosition.x, myScenery[i].myPosition.y) + myLastRenderPosition;
		posInCameraSpace.x /= -myScenery[i].myPosition.z;
		posInCameraSpace.y /= -myScenery[i].myPosition.z;

		posInCameraSpace += myLastRenderPosition;
		float distanceFromCenter = MT::Length(aGameCamera.GetCenter() - posInCameraSpace);
		float cameraRadius = MT::Length(aGameCamera.GetDimensions() * 0.5f);
		if (distanceFromCenter > cameraRadius)
		{
			myScenery[i] = myScenery.back();
			myScenery.pop_back();
		}
	}

	// Add new ones
	for (unsigned i = 0; i < 250; i++)
	{
		SceneryData tmpScenery;
		float distanceX = aGameCamera.GetDimensions().x + 1000;
		float distanceY = aGameCamera.GetDimensions().y + 1000;
		float angle = rand();
		tmpScenery.myPosition.x = -myLastRenderPosition.x + cos(angle) * distanceX + cos(angle) * MT::Randf() * distanceX;
		tmpScenery.myPosition.y = -myLastRenderPosition.y + -sin(angle) * distanceY + -sin(angle) * MT::Randf() * distanceY;
		tmpScenery.myPosition.z = 2.f + 0.5f * MT::Randf();
		tmpScenery.myRotation = 2 * MT_PI * MT::Randf();
		tmpScenery.myScale = sf::Vector2f(1, 1) / 5.f * tmpScenery.myPosition.z;
		tmpScenery.myType = static_cast<SceneryType>(rand() % static_cast<int>(SceneryType::Size));
		myScenery.push_back(tmpScenery);
	}
}