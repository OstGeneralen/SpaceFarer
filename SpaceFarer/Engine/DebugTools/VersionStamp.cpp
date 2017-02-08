#include "VersionStamp.h"
#include "SFML\Graphics\RenderTexture.hpp"

namespace Debug
{
	VersionStamp::VersionStamp(DebugWidget* aDebugWidget)
		: DebugDecorator(aDebugWidget)
	{
		myDebugString = "V: " + std::to_string(MAJOR) + "." + std::to_string(MINOR) + "." + std::to_string(PATCH);
		myDebugText.setString(myDebugString);
	}

	void VersionStamp::Load(const sf::RenderTexture & aRenderWindow)
	{
		DebugDecorator::Load(aRenderWindow);
		myDebugText.setPosition(10, aRenderWindow.getSize().y - (myDebugText.getLocalBounds().height * 2));
	}

	void VersionStamp::Render(sf::RenderTexture& aRenderWindow)
	{
		aRenderWindow.draw(myDebugText);
	}
}