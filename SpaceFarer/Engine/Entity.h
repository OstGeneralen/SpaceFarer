#pragma once
#include <SFML\System\Vector2.hpp>

class Entity
{
public:
	virtual void	SetPosition(const sf::Vector2f& aPosition);
	virtual const	sf::Vector2f& GetPosition() const;
protected:
	sf::Vector2f	myPosition;
};

