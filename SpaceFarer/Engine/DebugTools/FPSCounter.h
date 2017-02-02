#pragma once
#include "DebugDecorator.h"

namespace Debug
{
	class FPSCounter : public DebugDecorator
	{
	public:
		FPSCounter(DebugWidget* aDebugWidget);
		void Update(float aDeltaTime);
		void Render(sf::RenderWindow& aRenderWindow);
	private:
		int myCurrentFPS;
		float myTimer;
		float myTimeBetweenUpdates;
	};
}