#pragma once
#include <SFML\System\Vector3.hpp>

class Entity
{
public:
	void SetPosition(const sf::Vector3f& aPosition);
	const sf::Vector3f& GetPostition() const;
protected:
	sf::Vector3f myPosition;
};

