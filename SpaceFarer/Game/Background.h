#pragma once
#include "SFML\Graphics\Sprite.hpp"
#include "SFML\Graphics\Texture.hpp"
#include <vector>

namespace sf
{
	class RenderWindow;
}

enum class SceneryType
{
	SmallStar
};

struct SceneryData
{
	sf::Vector2f	myPosition;
	sf::Vector2f	myScale;
	float			myRotation;
	SceneryType		myType;
};

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

	sf::Texture* mySmallStarTexture;
	sf::Vector2f myLastRenderPosition;
	std::vector<SceneryData> myScenery;
	float myUpdateRadius;

	void UpdateStars();
};