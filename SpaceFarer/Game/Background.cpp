#include "Background.h"
#include "SFML\Graphics\RenderWindow.hpp"

Background::Background()
{
	myBackGroundTexture.loadFromFile("sprites/backgroundStars.png");
	myLayerOneSprite.setTextureRect({ 0,0,128,128 });
	myLayerTwoSprite.setTextureRect({ 128,0,128,128 });
	myLayerThreeSprite.setTextureRect({ 256, 0, 128,128 });
	myLayerOneSprite.setTexture(myBackGroundTexture);
	myLayerTwoSprite.setTexture(myBackGroundTexture);
	myLayerThreeSprite.setTexture(myBackGroundTexture);
}

void Background::CreateBackground(const sf::RenderWindow & aRenderWindow)
{

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
	
}

void Background::Render(sf::RenderWindow & aRenderWindow)
{ 
	int windowW = aRenderWindow.getSize().x;
	int windowH = aRenderWindow.getSize().y;
	int cameraX = static_cast<int>(aRenderWindow.getView().getCenter().x);
	int cameraY = static_cast<int>(aRenderWindow.getView().getCenter().y);

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
}
