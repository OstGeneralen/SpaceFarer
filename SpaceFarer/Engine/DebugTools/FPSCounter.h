#pragma once
#include "DebugDecorator.h"

namespace Debug
{
	class FPSCounter : public DebugDecorator
	{
	public:
		FPSCounter(DebugWidget* aDebugWidget);
		void	Update(float aDeltaTime) override;
		void	Render(sf::RenderWindow& aRenderWindow) override;
	private:
		int		myCurrentFPS;
		float	myTimer;
		float	myTimeBetweenUpdates;
	};
}