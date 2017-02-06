#pragma once
#include "SFML\System\Vector2.hpp"
#include "DebugTools\FPSCounter.h"
#include "DebugTools\DebugWidget.h"

namespace sf
{
	class RenderWindow;
}

namespace Debug
{
	class Tools : public DebugWidget
	{
	public:
		Tools();
		void Load(const sf::RenderWindow& aRenderWindow) override;
		void Update(float aDeltaTime) override;
		void Render(sf::RenderWindow& aRenderWindow) override;
	};
}

namespace D = Debug;