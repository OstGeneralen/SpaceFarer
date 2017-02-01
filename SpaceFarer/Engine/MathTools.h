#pragma once
#define MT_PI 3.141592f

namespace MathTools
{
	struct MTVector2
	{
		float x = 0;
		float y = 0;
	};

	static float Lerp(float aStartValue, float aEndValue, float aLerpValue)
	{
		return ((1.0f - aLerpValue) * aStartValue) + (aLerpValue * aEndValue);
	}

	static float ToDegrees(float aRadian)
	{
		return aRadian * (180.f / MT_PI);
	}

	static MTVector2 GetMiddlePoint(int aX, int aY, int aW, int aH)
	{
		MTVector2 returnVector;
		returnVector.x = static_cast<float>(aX + (aW / 2));
		returnVector.y = static_cast<float>(aY + (aH / 2));
		return returnVector;
	}
}

namespace MT = MathTools;