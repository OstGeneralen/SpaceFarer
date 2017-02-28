#include "Cursor.h"
#include "SFML\Graphics\RenderWindow.hpp"

Cursor & Cursor::GetInstance()
{
	static Cursor instance;
	return instance;
}

void Cursor::Render(sf::RenderWindow & aGameWindow)
{
	SetPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		NotifyObservers(EVENT_MOUSE_LMB_PRESSED, GetPosition().x, GetPosition().y);
	}

	Drawable::Render(aGameWindow);
}
