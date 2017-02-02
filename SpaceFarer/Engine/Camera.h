#pragma once
#include "SFML\Graphics\View.hpp"
#include "SFML\System\Vector2.hpp"

class Actor;

namespace sf
{
	class RenderWindow;
}

class Camera
{
public:
	Camera();
	void Resize(float aWidth, float aHeight);
	void SetTarget(Actor* aTarget);
	void Update(float aDeltaTime);
	void UseView(sf::RenderWindow& aWindow);
private:
	Actor* myTarget = nullptr;
	sf::Vector2f myTargetCenter;
	sf::View myView;
};