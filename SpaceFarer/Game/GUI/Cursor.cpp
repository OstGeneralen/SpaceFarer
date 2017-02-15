#include "Cursor.h"
#include "SFML\Graphics\RenderWindow.hpp"

void Cursor::Render(sf::RenderWindow & aGameWindow)
{
	SetPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));

	Drawable::Render(aGameWindow);
}
