#pragma once
#include <SFML\System\Vector2.hpp>
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

	static float Randf()
	{
		return abs(sinf(rand()));
	}

	static float Dot(const sf::Vector2f& aVector1, const sf::Vector2f& aVector2)
	{
		return aVector1.x * aVector2.x + aVector1.y * aVector2.y;
	}

	static float Length(const sf::Vector2f aVector)
	{
		return sqrt(aVector.x * aVector.x + aVector.y * aVector.y);
	}

	static float Length2(const sf::Vector2f aVector)
	{
		return aVector.x * aVector.x + aVector.y * aVector.y;
	}

	static void Normalize(sf::Vector2f& aVectorToNormalize)
	{
		sf::Vector2f tmpVector;
		tmpVector.x = aVectorToNormalize.x / Length(aVectorToNormalize);
		tmpVector.y = aVectorToNormalize.y / Length(aVectorToNormalize);
		aVectorToNormalize = tmpVector;
	}
}

namespace MT = MathTools;