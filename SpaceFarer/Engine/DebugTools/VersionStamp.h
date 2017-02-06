#pragma once
/* Versioning uses syntax:
   Major.Minor.Patch

   Major: Game is drastically changed and/or can be seen as a new release
   Minor: Game have had at least 10 patches that all contribute to a different game feel
   Patch: Bug fixes and tweaks to game that are noticable

   If Version number is increased a changelog must be written with all the major fixes and added/removed features

   0.0.1 counts as the Inertia commit (https://github.com/SpaceFarerOrg/SpaceFarer/commit/2f70d52d6bb1feaae0e3673145ac7a37cb7275be)
*/

#define MAJOR 0
#define MINOR 0
#define PATCH 1

#include "DebugDecorator.h"

namespace Debug
{

	class VersionStamp : public DebugDecorator
	{
	public:
		VersionStamp(DebugWidget* aDebugWidget);
		void Load(const sf::RenderWindow& aRenderWindow) override;
		void Render(sf::RenderWindow& aRenderWindow) override;
	};
}