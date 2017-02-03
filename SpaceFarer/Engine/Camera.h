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
	void SetCenter(Actor* aTarget);
	const sf::Vector2f& GetCenter() const;
	const sf::Vector2f& GetTargetPosition() const;
	void Update(float aDeltaTime);
	void UseView(sf::RenderWindow& aWindow);
	bool CanSee(const sf::Vector2f& aPosition);
	void Zoom(const float aFactor);
	const sf::Transform& GetTransform() const;
private:
	Actor* myTarget = nullptr;
	sf::Vector2f myTargetCenter;
	sf::View myView;
};