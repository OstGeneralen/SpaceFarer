#pragma once

namespace MathTools
{
	static float Lerp(float aStartValue, float aEndValue, float aLerpValue)
	{
		return ((1.0f - aLerpValue) * aStartValue) + (aLerpValue * aEndValue);
	}
}