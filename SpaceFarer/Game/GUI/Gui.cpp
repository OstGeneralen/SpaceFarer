#include "Gui.h"
#include "SFML\Graphics\RenderWindow.hpp"

void Gui::Load(const std::string & aTexPath, const std::string & aFontPath)
{
	myBarTex.loadFromFile(aTexPath);
	myBarActor.Init(&myBarTex, true);

	myTextFont.loadFromFile(aFontPath);
	myBalanceText = sf::Text("", myTextFont, 20U);
	myMovementText = sf::Text("", myTextFont, 20U);
	myFuelText = sf::Text("", myTextFont, 20U);
}

void Gui::SetPositions(const sf::RenderWindow & aRenderWindow)
{
	myBarActor.SetPosition({(aRenderWindow.getSize().x / 2.f), aRenderWindow.getSize().y - (myBarActor.GetSize().y / 2.f)});
	
	myBalanceText.setOrigin(myBalanceText.getLocalBounds().width / 2, 0);
	myBalanceText.setPosition(myBarActor.GetTransform().transformPoint(-myBarActor.GetSize().x / 3,-myBarActor.GetSize().y / 3));
	
	myMovementText.setOrigin(myMovementText.getLocalBounds().width / 2, 0);
	myMovementText.setPosition(myBarActor.GetTransform().transformPoint(myBarActor.GetSize().x / 3, -myBarActor.GetSize().y / 3));

	myFuelText.setOrigin(myFuelText.getLocalBounds().width / 2, 0);
	myFuelText.setPosition(myBalanceText.getPosition().x, myBalanceText.getPosition().y + myBalanceText.getLocalBounds().height * 2);
}

void Gui::Render(sf::RenderWindow & aRenderWindow)
{
	myBarActor.Render(aRenderWindow);
	aRenderWindow.draw(myBalanceText);
	aRenderWindow.draw(myMovementText);
	aRenderWindow.draw(myFuelText);
}

void Gui::Notify(GameEvent aEvent, int aValue)
{
	if (aEvent == EVENT_PLAYER_NEW_BALANCE)
	{
		myBalanceString = "Balance: " + std::to_string(aValue) + " sonars";
		myBalanceText.setString(myBalanceString);
	}
	if (aEvent == EVENT_PLAYER_NEW_FUEL_AMOUNT)
	{
		myFuelString = "Fuel: " + std::to_string(aValue) + " litres";
		myFuelText.setString(myFuelString);
	}
}

void Gui::Notify(GameEvent aEvent, float aX, float aY)
{
	if (aEvent == EVENT_PLAYER_NEW_VELOCITY)
	{
		myMovementString = "Directional Vectors\nX: " + std::to_string(static_cast<int>(aX)) + "\nY: " + std::to_string(static_cast<int>(aY));
		myMovementText.setString(myMovementString);
	}
}
