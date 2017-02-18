#pragma once
#include "Asteroid.h"
#include <vector>
#include "Observer\Observer.h"

namespace sf
{
	class RenderWindow;
}

class Camera;

class Debris : public Observer
{
public:
	void						Init();
	void						Update(float aDeltaTime, const Camera& aCamera, const sf::RenderWindow& aRenderWindow);
	void						Render(const Camera& aCamera, sf::RenderWindow& aRenderWindow);

	void						Notify(GameEvent aEvent, float aX, float aY) override;
private:
	void						SpawnAsteroid(const Camera& aCamera, const sf::RenderWindow& aGameWindow);
	
	std::vector<Actor*>			myDebris;
	
	sf::Vector2f				myOldPlayerPosition;
	sf::Vector2f				myPlayerPosition;
	
	const float					myDistanceBetweenSpawn = 200;
	int							mySpawnChance = 30;
};