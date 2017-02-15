#pragma once
#include "..\..\Engine\Drawable.h"

class HealthBar : public Drawable
{
public:
	void				Init(sf::Texture* aTexture) override;
	void				SetHealth(float aHealth, float aMaxHealth);
	void				SetPosition(const sf::Vector2f& aPosition) override;
private:
	int					myStartWidth;

};