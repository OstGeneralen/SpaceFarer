#include "Gui.h"
#include "SFML\Graphics\RenderWindow.hpp"
#include "..\..\TextureBank.h"

void Gui::Load(const std::string & aFontPath)
{
	myBarActor.Init(GET_TEXTURE("guiBar"), true);
}

void Gui::SetPositions(const sf::RenderWindow & aRenderWindow)
{
	myBarActor.SetPosition({(aRenderWindow.getSize().x / 2.f), aRenderWindow.getSize().y - (myBarActor.GetSize().y / 2.f)});
	
	myBalanceText.SetOriginToMiddle();
	myBalanceText.GetSFText().setPosition(myBarActor.GetTransform().transformPoint(-myBarActor.GetSize().x / 3,-myBarActor.GetSize().y / 3));
	
	myVelocityText.SetOriginToMiddle();
	myVelocityText.SetPosition(myBarActor.GetTransform().transformPoint(myBarActor.GetSize().x / 3, -myBarActor.GetSize().y / 3));

	myFuelText.SetOriginToMiddle();
	myFuelText.SetPosition({ myBalanceText.GetPosition().x, myBalanceText.GetPosition().y + myBalanceText.GetSize().y * 2 });
}

void Gui::Render(sf::RenderWindow & aRenderWindow)
{
	myBarActor.Render(aRenderWindow);
	myBalanceText.Render(aRenderWindow);
	myVelocityText.Render(aRenderWindow);
	myFuelText.Render(aRenderWindow);
}

void Gui::Notify(GameEvent aEvent, int aValue)
{
	if (aEvent == EVENT_PLAYER_NEW_BALANCE)
	{
		myBalanceText.SetString("Balance: " + std::to_string(aValue) + " sonars");
	}
	if (aEvent == EVENT_PLAYER_NEW_FUEL_AMOUNT)
	{
		if (aValue < 10)
		{
			myFuelText.ToggleWarningMode(true);
		}

		myFuelText.SetString("Fuel: " + std::to_string(aValue) + " litres");
	}
}

void Gui::Notify(GameEvent aEvent, float aX, float aY)
{
	if (aEvent == EVENT_PLAYER_NEW_VELOCITY)
	{
		myVelocityText.SetString("Directional Vectors\nX: " + std::to_string(static_cast<int>(aX)) + "\nY: " + std::to_string(static_cast<int>(aY)));
	}
}
