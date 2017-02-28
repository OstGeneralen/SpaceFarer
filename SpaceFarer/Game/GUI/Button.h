#pragma once
#include "..\..\Engine\Colliders\Colliders.h"
#include "..\..\Engine\Drawable.h"
#include "..\Observer\Observer.h"

template <class funcArg>
class Button : public Drawable, public Observer
{
public:
	void Init(sf::Texture* aTexture, funcArg& myArgument, void(*aFunctionToCall)(funcArg&));
	void Destroy();
	void Render(sf::RenderWindow& aGameWindow) override;
	void SetPosition(const sf::Vector2f& aPosition) override;
	void Notify(GameEvent aEvent, float aX, float aY) override;
private:
	AABBCollider* myCollider;
	funcArg* myArgument;
	void(*myFunctionToCall)(sf::RenderWindow&);
};

template <class funcArg>
void Button<funcArg>::Init(sf::Texture * aTexture, funcArg& aArgument, void(*function)(funcArg&))
{
	Drawable::Init(aTexture);
	myFunctionToCall = function;
	myArgument = &aArgument;

	SetOrigin({ mySprite.getLocalBounds().width / 2.f, mySprite.getLocalBounds().height / 2.f });
	myCollider = new AABBCollider(myPosition, mySprite.getLocalBounds().width, mySprite.getLocalBounds().height);
}

template<class funcArg>
inline void Button<funcArg>::Destroy()
{
	delete myCollider;
}

template <class object>
void Button<object>::Render(sf::RenderWindow & aGameWindow)
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
	if (aEvent == EVENT_MOUSE_LMB_PRESSED)
	{
		if (myCollider->IsCollidingWith({ aX, aY }))
		{
			myFunctionToCall(*myArgument);
		}
	}
}