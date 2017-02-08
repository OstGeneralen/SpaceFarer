#pragma once
#include "SFML\Graphics\View.hpp"
#include "SFML\System\Vector2.hpp"

class Entity;

namespace sf
{
	class RenderWindow;
}

class Camera
{
public:
	Camera();
	Camera(const sf::RenderWindow& aRenderWindow);
	void Resize(float aWidth, float aHeight);
	void SetTarget(Entity* aTarget);
	void SetCenter(Entity* aTarget);
	const sf::Vector2f& GetCenter() const;
	const sf::Vector2f& GetTargetPosition() const;
	void Update(float aDeltaTime);
	void UseView(sf::RenderWindow& aWindow);
	bool CanSee(const sf::Vector2f& aPosition);
	void Zoom(const float aFactor);
	const sf::Transform& GetTransform() const;
private:
	Entity* myTarget = nullptr;
	sf::Vector2f myTargetCenter;
	sf::View myView;
};