#include "GuiText.h"
#include "SFML\Graphics\RenderWindow.hpp"

GuiText::GuiText()
{
	myFont.loadFromFile("fonts/helvetica.ttf");
	myString = "";
	myText = sf::Text("", myFont, 20U);

	myText.setOutlineThickness(1);
	myText.setFillColor(myStandardTextFill);
	myText.setOutlineColor(myTextOutline);
}

sf::Text& GuiText::GetSFText()
{
	return myText;
}

void GuiText::SetString(const sf::String & aString)
{
	myText.setString(aString);

	mySize = {myText.getLocalBounds().width, myText.getLocalBounds().height};
}

void GuiText::SetColor(const sf::Color & aColor)
{
	myText.setFillColor(aColor);
}

void GuiText::SetPosition(const sf::Vector2f aPostition)
{
	myText.setPosition(aPostition);
}

const sf::Vector2f& GuiText::GetPosition() const
{
	return myText.getPosition();
}

const sf::Vector2f & GuiText::GetSize() const
{
	return mySize;
}

void GuiText::ToggleWarningMode(bool aIsWarning)
{
	if (aIsWarning)
	{
		myText.setFillColor(myWarningTextFill);
	}
	else if (!aIsWarning)
	{
		myText.setFillColor(myStandardTextFill);
	}
}

void GuiText::SetOriginToMiddle(bool aInX, bool aInY)
{
	if (aInX)
	{
		myText.setOrigin(myText.getLocalBounds().width / 2, myText.getOrigin().y);
	}

	if(aInY)
	{
		myText.setOrigin(myText.getOrigin().x, myText.getLocalBounds().height / 2);
	}
}

void GuiText::Render(sf::RenderWindow & aRenderWindow)
{
	aRenderWindow.draw(myText);
}

