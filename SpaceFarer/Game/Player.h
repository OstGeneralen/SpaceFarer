#pragma once
#include "..\Engine\Actor.h"

class Player : public Actor
{
public:
	void Update(float aDeltaTime) override;
};