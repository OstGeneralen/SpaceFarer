#include "Actor.h"
#include <SFML\Graphics\RenderWindow.hpp>
#include "MathTools.h"

void Actor::Init(sf::Texture* aTexture, bool aOriginIsMiddle, const sf::Vector2f& aStartPosition, const float aMass, const float aRestitution)
{
	myTexture = aTexture;
	mySprite.setTextureRect({ 0,0, static_cast<int>(myTexture->getSize().x), static_cast<int>(myTexture->getSize().y) });
	mySprite.setTexture(*aTexture);
	
	if (aOriginIsMiddle)
	{
		MT::MTVector2 middlePoint;
		middlePoint = MathTools::GetMiddlePoint(0, 0, mySprite.getTextureRect().width, mySprite.getTextureRect().height);
		mySprite.setOrigin(middlePoint.x, middlePoint.y);
	}

	myVelocity = { 0,0 };
	myTransform.setPosition(aStartPosition);
	mySprite.setPosition(aStartPosition);
	myMass = aMass;
	myRestitution = aRestitution;
}

void Actor::Update(float aDeltaTime)
{
	myTransform.move(myVelocity * aDeltaTime);
}

void Actor::Render(sf::RenderWindow& aRenderWindow)
{
	mySprite.setPosition(myTransform.getPosition());
	mySprite.setRotation(myTransform.getRotation());
	aRenderWindow.draw(mySprite);
}

void Actor::SetPosition(const sf::Vector2f & aPosition)
{
	myTransform.setPosition(aPosition);
}

const sf::Vector2f & Actor::GetPosition() const
{
	return myTransform.getPosition();
}

const sf::Vector2f & Actor::GetSize() const
{
	return{ mySprite.getLocalBounds().width, mySprite.getLocalBounds().height };
}

const sf::Transform & Actor::GetTransform() const
{
	return myTransform.getTransform();
}

void Actor::SetVelocity(const sf::Vector2f & aVelocity)
{
	myVelocity = aVelocity;
}

bool Actor::CheckIfColliding(const Actor & aOther) const
{
	float distance = abs(MT::Length(this->GetPosition() - aOther.GetPosition()));

	if (distance < this->GetRadius() + aOther.GetRadius())
	{
		return true;
	}

	return false;

}

const sf::Vector2f & Actor::GetVelocity() const
{
	return myVelocity;
}

void Actor::ChangeVelocity(const sf::Vector2f & aVelocity)
{
	myVelocity += aVelocity;
}

const float Actor::GetRadius() const
{
	return static_cast<float>(myTexture->getSize().x) / 2.f;
}

const float Actor::GetMass() const
{
	return myMass;
}

const float Actor::GetRestitution() const
{
	return myRestitution;
}
