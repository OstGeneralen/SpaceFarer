#pragma once
#include "SFML\Graphics\Transform.hpp"
#include "SFML\Graphics\Sprite.hpp"
#include "..\..\Engine\Drawable.h"

namespace sf
{
	class RenderWindow;
}

class RadarPointer : public Drawable
{
public:
	RadarPointer() = default;
	void						SetTargetPosition(const sf::Vector2f& aTargetPosition);
	void						Update(const sf::Vector2f& aPlayerPosition);
private:
	sf::Vector2f				myDirection;
	sf::Vector2f				myTargetPosition;
};