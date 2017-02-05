#pragma once
#include "..\Observer\Observer.h"
#include "SFML\Graphics\Texture.hpp"
#include "SFML\Graphics\Text.hpp"
#include "..\..\Engine\Actor.h"
#include <string>

namespace sf
{
	class RenderWindow;
}

class Gui : public Observer 
{
public:
	void			Load(const std::string& aTexPath, const std::string& aFontPath);
	void			SetPositions(const sf::RenderWindow& aRenderWindow);
	void			Render(sf::RenderWindow& aRenderWindow);
	void			Notify(GameEvent aEvent, int aValue) override;
	void			Notify(GameEvent aEvent, float aX, float aY) override;
private:
	sf::Texture		myBarTex;
	sf::Font		myTextFont;
	sf::Text		myBalanceText;
	sf::Text		myMovementText;
	sf::String		myBalanceString;
	sf::String		myMovementString;
	Actor			myBarActor;

};