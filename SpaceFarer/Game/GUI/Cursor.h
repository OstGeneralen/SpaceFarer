#pragma once
#include "..\..\Engine\Drawable.h"
#include "..\Observer\Subject.h"
#include "SFML\Window\Mouse.hpp"

class Cursor : public Drawable, public Subject
{
public:
	void Render(sf::RenderWindow& aGameWindow) override;
};
