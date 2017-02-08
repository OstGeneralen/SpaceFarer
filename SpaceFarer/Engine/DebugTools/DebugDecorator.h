#pragma once
#include "DebugWidget.h"

namespace Debug
{
	class DebugDecorator : public DebugWidget
	{
	public:
		DebugDecorator(DebugWidget* aWidget) : myWidget(aWidget) {};
		
		void Load(const sf::RenderTexture& aRenderWindow)
		{
			myWidget->Load(aRenderWindow);
		}

		void Update(float aDeltaTime) override
		{
			myWidget->Update(aDeltaTime);
		}
		
		void Render(sf::RenderTexture& aRenderWindow) override
		{
			myWidget->Render(aRenderWindow);
		}
	private:
		DebugWidget* myWidget;
	};
}