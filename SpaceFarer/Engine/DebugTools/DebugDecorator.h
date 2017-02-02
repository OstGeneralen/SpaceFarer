#pragma once
#include "DebugWidget.h"

namespace Debug
{
	class DebugDecorator : public DebugWidget
	{
	public:
		DebugDecorator(DebugWidget* aWidget) : myWidget(aWidget) {};
		
		void Update(float aDeltaTime) override
		{
			myWidget->Update(aDeltaTime);
		}
		
		void Render(sf::RenderWindow& aRenderWindow) override
		{
			myWidget->Render(aRenderWindow);
		}
	private:
		DebugWidget* myWidget;
	};
}