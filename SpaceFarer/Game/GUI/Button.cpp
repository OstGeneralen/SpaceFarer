#include "Button.h"

void Button::InitButton(const std::function<void()>& aFuncToCallOnPress)
{
	myFunctionToCallOnPress = aFuncToCallOnPress;
}

void Button::Notify(GameEvent aEvent, float aX, float aY)
{
	if (aEvent == GameEvent::EVENT_LMB_PRESSED && CheckIfColliding({ aX, aY }))
	{
		myFunctionToCallOnPress();
	}
}
