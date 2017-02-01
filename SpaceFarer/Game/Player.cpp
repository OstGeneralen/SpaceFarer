#include "Player.h"
#include <SFML\Window\Event.hpp>
#include <SFML\Window\Keyboard.hpp>

void Player::Update(float aDeltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		myPosition.x += 200.f * aDeltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		myPosition.x -= 200.f * aDeltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		myPosition.y -= 200.f * aDeltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		myPosition.y += 200.f * aDeltaTime;
	}

}