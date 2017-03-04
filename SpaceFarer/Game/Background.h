#pragma once
#include "SFML\Graphics\Sprite.hpp"
#include "SFML\Graphics\Texture.hpp"
#include "SFML\System\Vector2.hpp"
#include "SFML\System\Vector3.hpp"
#include <vector>

class Camera;

namespace sf
{
	class RenderWindow;
}

enum class SceneryType
{
	SmallStar = 0,
	Planet = 1,
	Size = 2
};

struct SceneryData
{
	sf::Vector3f	myPosition;
	sf::Vector2f	myScale;
	float			myRotation;
	SceneryType		myType;
};

class Background
{
public:
	Background();
	//void						Update(float aDeltaTime);
	void						CreateBackground(const sf::RenderWindow& aRenderWindow);
	void						Render(sf::RenderWindow& aRenderWindow, Camera& aGameCamera);
	void						Disable();
	void						Activate();
private:
	sf::Sprite					myLayerOneSprite;
	sf::Sprite					myLayerTwoSprite;
	sf::Sprite					myLayerThreeSprite;
	std::vector<sf::Vector2f>	myRenderPositions;

	sf::Vector2f				myLastRenderPosition;
	std::vector<SceneryData>	myScenery;
	float						myUpdateRadius;
	bool						myIsDisabled;

	void						UpdateStars(const Camera& aGameCamera);
};