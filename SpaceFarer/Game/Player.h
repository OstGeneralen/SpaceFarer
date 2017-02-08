#pragma once
#include "..\Engine\Actor.h"
#include "Observer\Subject.h"
#include "Ship\Ship.h"

class Player : public Entity, public Subject
{
public:
	Player();
	void			Update(float aDeltaTime);
	void			Render(sf::RenderTexture& aRenderWindow);
	void			GiveShip(Ship* aShip);
	Ship&			GetShip() const;
private:
	Ship*			myShip = nullptr;
};