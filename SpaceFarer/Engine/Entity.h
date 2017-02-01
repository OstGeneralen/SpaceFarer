#pragma once
#include <SFML\System\Vector2.hpp>

class Entity
{
public:
	void SetPosition(const sf::Vector2f& aPosition);
	const sf::Vector2f& GetPostition() const;
protected:
	sf::Vector2f myPosition;
};

