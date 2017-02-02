#include "FPSCounter.h"
#include "SFML\Graphics\RenderWindow.hpp"

Debug::FPSCounter::FPSCounter(DebugWidget* aDebugWidget)
	: Debug::DebugDecorator(aDebugWidget)
{
	myCurrentFPS = 0;
	myTimer = 0;
	myTimeBetweenUpdates = 1;
}

void Debug::FPSCounter::Update(float aDeltaTime)
{
	DebugDecorator::Update(aDeltaTime);
	myTimer += aDeltaTime;

	if (myTimer >= myTimeBetweenUpdates)
	{
		myTimer = 0;
		myCurrentFPS = static_cast<int>(1.f / aDeltaTime);
	}

	myDebugString = "FPS: " + std::to_string(myCurrentFPS);
	myDebugText.setString(myDebugString);
}

void Debug::FPSCounter::Render(sf::RenderWindow& aRenderWindow)
{
	DebugDecorator::Render(aRenderWindow);
	aRenderWindow.draw(myDebugText);
}