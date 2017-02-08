#pragma once
#include "SFML\Graphics\Text.hpp"

namespace sf
{
	class RenderTexture;
}

namespace Debug
{
	class DebugWidget
	{
	public:
		DebugWidget()
		{
			myDebugFont.loadFromFile("fonts/helvetica.ttf");
			myDebugText = sf::Text("", myDebugFont);
			myDebugText.setFillColor(sf::Color(200, 200, 75, 255));
			myDebugText.setOutlineColor(sf::Color(0, 0, 0, 255));
			myDebugText.setOutlineThickness(1);
		}
		virtual void Load(const sf::RenderTexture& aRenderWindow) = 0;
		virtual void Update(float aDeltaTime) = 0;
		virtual void Render(sf::RenderTexture& aRenderWindow) = 0;
	protected:
		sf::Text myDebugText;
		sf::Font myDebugFont;
		sf::String myDebugString;
	};
}