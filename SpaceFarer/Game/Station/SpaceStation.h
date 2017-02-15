#pragma once
#include "..\..\Engine\Actor.h"
#include "SFML\System\Vector2.hpp"

enum class ExitPoint
{
	Up,
	Down,
	Left,
	Right,
};

class SpaceStation : public Actor
{
public:
	void			SetExitPoint(ExitPoint aExitPoint);
	const			sf::Vector2f& GetExitPoint() const;
private:
	sf::Vector2f	myExitPoint;

};