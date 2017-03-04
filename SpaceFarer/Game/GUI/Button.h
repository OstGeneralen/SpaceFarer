#pragma once
#include "..\..\Engine\Colliders\Colliders.h"
#include "..\..\Engine\Drawable.h"
#include "..\Observer\Observer.h"

template <class OwnerClass>
class Button : public Drawable, public Observer
{
public:
	void				Init(sf::Texture* aTexture, OwnerClass* aOwnerObject, void(OwnerClass::*aFunctionToCall)());
	void				Destroy();
	void				Render(sf::RenderWindow& aGameWindow) override;
	void				SetPosition(const sf::Vector2f& aPosition) override;
	void				Notify(GameEvent aEvent, float aX, float aY) override;
private:
	AABBCollider*		myCollider;
	OwnerClass*			myOwnerObject;
	void(OwnerClass::*myFunctionToCall)();
};

template <class OwnerClass>
void Button<OwnerClass>::Init(sf::Texture * aTexture, OwnerClass* aOwnerObject, void(OwnerClass::*aFunctionToCall)())
{
	Drawable::Init(aTexture);
	myFunctionToCall = aFunctionToCall;
	myOwnerObject = aOwnerObject;

	SetOrigin({ mySprite.getLocalBounds().width / 2.f, mySprite.getLocalBounds().height / 2.f });
	myCollider = new AABBCollider(myPosition, mySprite.getLocalBounds().width, mySprite.getLocalBounds().height);
}

template<class OwnerClass>
inline void Button<OwnerClass>::Destroy()
{
	delete myCollider;
	myCollider = nullptr;
}

template <class OwnerClass>
void Button<OwnerClass>::Render(sf::RenderWindow & aGameWindow)
{
	Drawable::Render(aGameWindow);
	myCollider->Render(aGameWindow);
}

template<class funcArg>
inline void Button<funcArg>::SetPosition(const sf::Vector2f& aPosition)
{
	Drawable::SetPosition(aPosition);
	myCollider->SetPosition(aPosition);
}

template <class object>
void Button<object>::Notify(GameEvent aEvent, float aX, float aY)
{
	if (myCollider != nullptr)
	{
		if (aEvent == EVENT_MOUSE_LMB_PRESSED)
		{
			if (myCollider->IsCollidingWith({ aX, aY }))
			{
				(myOwnerObject->*myFunctionToCall)();
			}
		}
	}
}