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

	static sf::Vector2f Lerp(const sf::Vector2f& aStartValue, const sf::Vector2f& aEndValue, float aLerpValue)
	{
		return{ Lerp(aStartValue.x, aEndValue.x, aLerpValue), Lerp(aStartValue.y, aEndValue.y, aLerpValue) };
	}

	static float ToDegrees(float aRadian)
	{
		return aRadian * (180.f / MT_PI);
	}

	static float ToRadians(const float aDegree)
	{
		return (aDegree * MT_PI) / 180.f;
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
		return static_cast<float>(abs(sinf(static_cast<float>(rand()))));
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

	template <typename T>
	static T Min(T aNr1, T aNr2)
	{
		return aNr1 < aNr2 ? aNr1 : aNr2;
	}

	template <typename T>
	static T Max(T aNr1, T aNr2)
	{
		return aNr1 > aNr2 ? aNr1 : aNr2;
	}
}

namespace MT = MathTools;