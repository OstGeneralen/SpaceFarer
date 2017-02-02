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

void Camera::Resize(float aWidth, float aHeight)
{
	myView = sf::View({ 0,0,aWidth,aHeight });
}

void Camera::SetTarget(Actor* aTarget)
{
	myTarget = aTarget;
}

void Camera::SetCenter(Actor * aTarget)
{
	myView.setCenter(aTarget->GetPosition());
}

void Camera::Update(float aDeltaTime)
{
	if (myTarget != nullptr)
	{
		sf::Vector2f newCenter = myView.getCenter();
		newCenter.x = MT::Lerp(newCenter.x, myTarget->GetPosition().x, 20.f * aDeltaTime);
		newCenter.y = MT::Lerp(newCenter.y, myTarget->GetPosition().y, 20.f * aDeltaTime);
		myView.setCenter(newCenter);
	}
}

void Camera::UseView(sf::RenderWindow & aWindow)
{
	aWindow.setView(myView);
}

