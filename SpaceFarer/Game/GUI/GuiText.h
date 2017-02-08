#pragma once
#include "SFML\Graphics\Text.hpp"

namespace sf
{
	class RenderTexture;
}

class GuiText
{
public:
	GuiText();
	sf::Text&			GetSFText();
	void				Render(sf::RenderTexture& aRenderWindow);
	void				SetString(const sf::String& aString);
	void				SetColor(const sf::Color& aColor);
	void				SetOriginToMiddle(bool aInX = true, bool aInY = false);
	void				SetPosition(const sf::Vector2f aPostition);
	const				sf::Vector2f& GetPosition() const;
	const				sf::Vector2f& GetSize() const;
	void				ToggleWarningMode(bool aIsWarning);
private:
	sf::Text			myText;
	sf::String			myString;
	sf::Font			myFont;
	sf::Vector2f		mySize;
	const sf::Color		myStandardTextFill = sf::Color(225, 225, 225, 255);
	const sf::Color		myWarningTextFill = sf::Color(225, 30, 30, 255);
	const sf::Color		myTextOutline = sf::Color(25, 25, 25, 255);
};