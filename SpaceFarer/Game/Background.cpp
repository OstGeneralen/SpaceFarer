#include "Background.h"
#include "SFML\Graphics\RenderTexture.hpp"
#include "..\TextureBank.h"
#include "..\Engine\MathTools.h"
#include <assert.h>

Background::Background()
{
}

void Background::CreateBackground(const sf::RenderTexture & aRenderWindow)
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
	UpdateStars();
	myLastRenderPosition = aRenderWindow.getView().getCenter();
	myUpdateRadius = 500;
}

void Background::Render(sf::RenderTexture & aRenderWindow)
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

	if (MT::Length(sf::Vector2f(cameraX, cameraY) - myLastRenderPosition) > myUpdateRadius / 2)
	{
		myLastRenderPosition = sf::Vector2f(cameraX, cameraY);
		UpdateStars();
	}

	sf::Sprite renderingSprite;
	for (unsigned i = 0; i < myScenery.size(); ++i)
	{
		switch (myScenery[i].myType)
		{
		case SceneryType::SmallStar:
			renderingSprite.setTexture(*mySmallStarTexture);
			break;
		default:
			assert(false && "Non-existing type :D");
			break;
		}
		renderingSprite.setOrigin(0.5f, 0.5f);
		renderingSprite.setScale(myScenery[i].myScale);
		renderingSprite.setPosition(myScenery[i].myPosition);
		renderingSprite.setRotation(myScenery[i].myRotation);
		aRenderWindow.draw(renderingSprite);
	}
}

void Background::UpdateStars()
{
	for (unsigned i = 0; i < 10; i++)
	{
		SceneryData tmpScenery;
		float angle = rand();
		tmpScenery.myPosition.x = myLastRenderPosition.x + MT::Randf() * 5 * myUpdateRadius * cos(angle);
		tmpScenery.myPosition.y = myLastRenderPosition.y + MT::Randf() * 5 * myUpdateRadius * sin(angle);
		tmpScenery.myRotation = 2 * MT_PI * MT::Randf();
		tmpScenery.myScale = (0.25f + 0.75f * MT::Randf()) * sf::Vector2f(1, 1);
		tmpScenery.myType = SceneryType::SmallStar;
		myScenery.push_back(tmpScenery);
	}
}
