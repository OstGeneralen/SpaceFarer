#include "Gui.h"
#include "SFML\Graphics\RenderWindow.hpp"

void Gui::Load(const std::string & aTexPath, const std::string & aFontPath)
{
	myBarTex.loadFromFile(aTexPath);
	myBarActor.Init(&myBarTex, true);

	myTextFont.loadFromFile(aFontPath);
	myBalanceText = sf::Text("", myTextFont, 12U);
	myMovementText = sf::Text("", myTextFont, 12U);
}

void Gui::SetPositions(const sf::RenderWindow & aRenderWindow)
{
	myBarActor.SetPosition({ 600,30 });
	myBalanceText.setPosition({ 300, 15});
	myMovementText.setPosition({ 500, 15 });
}

void Gui::Render(sf::RenderWindow & aRenderWindow)
{
	myBarActor.Render(aRenderWindow);
	aRenderWindow.draw(myBalanceText);
	aRenderWindow.draw(myMovementText);
}

void Gui::Notify(GameEvent aEvent, int aValue)
{
	if (aEvent == EVENT_PLAYER_NEW_BALANCE)
	{
		myBalanceString = "Balance: " + std::to_string(aValue) + " sonars";
		myBalanceText.setString(myBalanceString);
	}
}

void Gui::Notify(GameEvent aEvent, float aX, float aY)
{
	if (aEvent == EVENT_PLAYER_NEW_VELOCITY)
	{
		myMovementString = "Directional Vectors\nX: " + std::to_string(aX) + "\nY: " + std::to_string(aY);
		myMovementText.setString(myMovementString);
	}
}
