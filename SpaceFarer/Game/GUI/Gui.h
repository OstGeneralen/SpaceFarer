#pragma once
#include "..\Observer\Observer.h"
#include "SFML\Graphics\Texture.hpp"
#include "..\..\Engine\Actor.h"
#include <string>
#include "GuiText.h"

namespace sf
{
	class RenderTexture;
}

class Gui : public Observer 
{
public:
	void			Load();
	void			SetPositions(const sf::RenderTexture& aRenderWindow);
	void			Render(sf::RenderTexture& aRenderWindow);
	void			Notify(GameEvent aEvent, int aValue) override;
	void			Notify(GameEvent aEvent, float aX, float aY) override;
	void			Notify(GameEvent aEvent, const sf::String& aString) override;
private:
	sf::Texture		myBarTex;
	GuiText			myFuelText;
	GuiText			myBalanceText;
	GuiText			myVelocityText;
	GuiText			myShipText;
	Actor			myBarActor;

};