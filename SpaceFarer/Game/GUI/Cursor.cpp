#include "Cursor.h"
#include "SFML\Graphics\RenderWindow.hpp"

void Cursor::Render(sf::RenderWindow & aGameWindow)
{
	SetPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		NotifyObservers(EVENT_LMB_PRESSED, GetPosition().x, GetPosition().y);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle))
	{
		NotifyObservers(EVENT_MMB_PRESSED, GetPosition().x, GetPosition().y);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		NotifyObservers(EVENT_RMB_PRESSED, GetPosition().x, GetPosition().y);
	}

	Drawable::Render(aGameWindow);
}
