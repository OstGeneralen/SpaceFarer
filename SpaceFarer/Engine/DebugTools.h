#pragma once
#include "SFML\System\Vector2.hpp"
#include "DebugTools\FPSCounter.h"
#include "DebugTools\DebugWidget.h"

namespace sf
{
	class RenderTexture;
}

namespace Debug
{
	class Tools : public DebugWidget
	{
	public:
		Tools();
		void Load(const sf::RenderTexture& aRenderWindow) override;
		void Update(float aDeltaTime) override;
		void Render(sf::RenderTexture& aRenderWindow) override;
	};
}

namespace D = Debug;