#include "VersionStamp.h"
#include "SFML\Graphics\RenderWindow.hpp"

namespace Debug
{
	VersionStamp::VersionStamp(DebugWidget* aDebugWidget)
		: DebugDecorator(aDebugWidget)
	{
		myDebugString = "V: " + VERSION_STRING;
		myDebugText.setString(myDebugString);
	}

	void VersionStamp::Load(const sf::RenderWindow & aRenderWindow)
	{
		DebugDecorator::Load(aRenderWindow);
		myDebugText.setPosition(10, aRenderWindow.getView().getSize().y - myDebugText.getGlobalBounds().height * 2);
	}

	void VersionStamp::Render(sf::RenderWindow& aRenderWindow)
	{
		aRenderWindow.draw(myDebugText);
	}
}