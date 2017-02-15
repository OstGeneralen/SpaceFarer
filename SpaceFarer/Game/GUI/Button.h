#pragma once
#include "..\..\Engine\Actor.h"
#include "..\Observer\Observer.h"
#include <functional>


class Button : public Actor, public Observer
{
public:
	void InitButton(const std::function<void()>& aFuncToCallOnPress);
	void Notify(GameEvent aEvent, float aX, float aY) override;
private:
	std::function<void()> myFunctionToCallOnPress;

};