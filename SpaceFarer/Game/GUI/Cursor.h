#pragma once
#include "..\..\Engine\Drawable.h"
#include "SFML\Window\Mouse.hpp"

class Cursor : public Drawable
{
public:
	void Render(sf::RenderWindow& aGameWindow) override;
};
