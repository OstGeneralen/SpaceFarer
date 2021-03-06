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
	void					Resize(float aWidth, float aHeight);
	void					Update(float aDeltaTime);
	void					UseView(sf::RenderWindow& aWindow);
	
	void					SetTarget(Entity* aTarget);
	const sf::Vector2f&		GetTargetPosition() const;

	void					SetCenter(Entity* aTarget);
	const sf::Vector2f&		GetCenter() const;
	
	
	bool					CanSee(const sf::FloatRect& aHitBox) const;
	bool					CanSee(const sf::Vector2f& aPoint) const;
	
	void					Zoom(const float aFactor);
	const					sf::Transform& GetTransform() const;
	const					sf::Vector2f& GetDimensions() const;
private:
	Entity*					myTarget = nullptr;
	sf::Vector2f			myTargetCenter;
	sf::View				myView;
};