#include "Actor.h"
#include <SFML\Graphics\RenderWindow.hpp>
#include "MathTools.h"
#include <assert.h>

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
	
	if (myCollider != nullptr)
	{
		myCollider->SetPosition(GetPosition());
	}
}

void Actor::Render(sf::RenderWindow& aRenderWindow)
{
	mySprite.setPosition(myTransform.getPosition());
	mySprite.setRotation(myTransform.getRotation());
	aRenderWindow.draw(mySprite);
	
#ifdef _DEBUG
	if (myCollider != nullptr)
	{
		myCollider->Render(aRenderWindow);
	}
#endif 


}

void Actor::SetPosition(const sf::Vector2f & aPosition)
{
	myTransform.setPosition(aPosition);
	mySprite.setPosition(aPosition);

	if (myCollider != nullptr)
	{
		myCollider->SetPosition(aPosition);
	}
}

const sf::Vector2f & Actor::GetPosition() const
{
	return myTransform.getPosition();
}

const sf::Vector2f & Actor::GetSize() const
{
	//Will generate warning "returning address of local variable"
	//Until further notice this warning can be left
	return{ mySprite.getLocalBounds().width, mySprite.getLocalBounds().height };
}

const sf::Transform & Actor::GetTransform() const
{
	return myTransform.getTransform();
}

const sf::Transformable & Actor::GetTransformable() const
{
	return myTransform;
}

void Actor::SetVelocity(const sf::Vector2f & aVelocity)
{
	myVelocity = aVelocity;
}

bool Actor::CheckIfColliding(const Actor & aActor)
{
	assert(&aActor != this && "Checking collision against self");

	if (myCollider != nullptr)
	{
		CircleCollider* testCircleCollider = dynamic_cast<CircleCollider*>(&aActor.GetCollider());

		if (testCircleCollider != nullptr)
		{
			return myCollider->IsCollidingWith(*testCircleCollider);
		}

		AABBCollider* testAABBCollider = dynamic_cast<AABBCollider*>(&aActor.GetCollider());

		if (testAABBCollider != nullptr)
		{
			return myCollider->IsCollidingWith(*testAABBCollider);
		}
	}
	return false;
}

sf::FloatRect Actor::GetViewHitBox()
{
	return mySprite.getGlobalBounds();
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

void Actor::GiveCollider(Collider * aCollider)
{
	if (myCollider != nullptr)
	{
		delete myCollider;
		myCollider = nullptr;
	}

	myCollider = aCollider;
	aCollider = nullptr;
}

Collider& Actor::GetCollider() const
{
	return *myCollider;
}
