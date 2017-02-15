#pragma once
#include "..\..\Engine\Drawable.h"
#include "RadarPointer.h"

class Radar : public Drawable
{
public:
	void			Init(sf::Texture* aTexture) override;
	void			Render(sf::RenderWindow& aRenderWindow) override;
	void			SetPosition(const sf::Vector2f& aPosition) override;
	void			SetPlayerTarget(const sf::Vector2f& aTarget);
	void			UpdatePlayerPosition(const sf::Vector2f& aPosition);

private:
	RadarPointer	myRadarPointer;
};