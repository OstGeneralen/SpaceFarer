#pragma once
#include "SFML\Graphics\Sprite.hpp"
#include "SFML\Graphics\Texture.hpp"
#include <vector>

namespace sf
{
	class RenderWindow;
}

class Background
{
public:
	Background();
	//void Update(float aDeltaTime);
	void CreateBackground(const sf::RenderWindow& aRenderWindow);
	void Render(sf::RenderWindow& aRenderWindow);
private:
	sf::Sprite myLayerOneSprite;
	sf::Sprite myLayerTwoSprite;
	sf::Sprite myLayerThreeSprite;
	std::vector<sf::Vector2f> myRenderPositions;
};