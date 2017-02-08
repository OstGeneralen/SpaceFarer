#include "Camera.h"
#include "Actor.h"
#include "SFML\Graphics\RenderWindow.hpp"
#include "MathTools.h"

Camera::Camera()
{
	float aW = static_cast<float>(sf::VideoMode::getDesktopMode().width);
	float aH = static_cast<float>(sf::VideoMode::getDesktopMode().height);
	Resize(aW, aH);
}

Camera::Camera(const sf::RenderWindow & aRenderWindow)
{
	float aW = aRenderWindow.getSize().x;
	float aH = aRenderWindow.getSize().y;
	Resize(aW, aH);
}

void Camera::Resize(float aWidth, float aHeight)
{
	myView = sf::View({ 0,0,aWidth,aHeight });
}

void Camera::SetTarget(Entity* aTarget)
{
	myTarget = aTarget;
}

void Camera::SetCenter(Entity* aTarget)
{
	myView.setCenter(aTarget->GetPosition());
}

const sf::Vector2f & Camera::GetCenter() const
{
	return myTargetCenter;
}

const sf::Vector2f & Camera::GetTargetPosition() const
{
	return myTarget->GetPosition();
}

void Camera::Update(float aDeltaTime)
{
	if (myTarget != nullptr)
	{
		sf::Vector2f newCenter = myView.getCenter();

		newCenter.x = MT::Lerp(newCenter.x, myTarget->GetPosition().x, 5.f * aDeltaTime);
		newCenter.y = MT::Lerp(newCenter.y, myTarget->GetPosition().y, 5.f * aDeltaTime);

		myView.setCenter(newCenter);
	}
}

void Camera::UseView(sf::RenderWindow & aWindow)
{
	aWindow.setView(myView);
}

bool Camera::CanSee(const sf::Vector2f & aPosition)
{
	sf::FloatRect myViewInWorldSpace(myTarget->GetPosition() - myView.getSize() * 0.5f, myView.getSize());
	return myViewInWorldSpace.contains(aPosition);
}

void Camera::Zoom(const float aFactor)
{
	myView.zoom(aFactor);
}

const sf::Transform & Camera::GetTransform() const
{
	return myView.getTransform();
}

