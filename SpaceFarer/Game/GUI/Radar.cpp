#include "Radar.h"
#include "..\..\TextureBank.h"
#include "..\..\Engine\MathTools.h"

void Radar::Init(sf::Texture * aTexture)
{
	Drawable::Init(aTexture);

	SetOrigin({GetSpriteDimensions().x / 2, GetSpriteDimensions().y / 2});

	myRadarPointer.Init(GET_TEXTURE("radarPointer"));
}

void Radar::Render(sf::RenderWindow & aRenderWindow)
{
	Drawable::Render(aRenderWindow);
	myRadarPointer.Render(aRenderWindow);
}

void Radar::SetPosition(const sf::Vector2f & aPosition)
{
	Drawable::SetPosition(aPosition);

	myRadarPointer.SetPosition(myTransform.getPosition());
}

void Radar::SetPlayerTarget(const sf::Vector2f & aTarget)
{
	myRadarPointer.SetTargetPosition(aTarget);
}

void Radar::UpdatePlayerPosition(const sf::Vector2f & aPosition)
{
	myRadarPointer.Update(aPosition);
}
