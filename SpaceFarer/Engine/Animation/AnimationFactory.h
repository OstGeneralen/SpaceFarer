#pragma once
#include <string>
#include "..\json.hpp"

#define GET_ANIMATION(aAnimationName) AnimationFactory::GetInstance().GetAnimation(aAnimationName);
#define DESTROY_ANIMATION(aAnimation) AnimationFactory::GetInstance().DestroyAnimation(aAnimation);

class Animation;

class AnimationFactory
{
public:
	static AnimationFactory& GetInstance();
	void		Init(const std::string& aAnimationsJson);
	Animation*	GetAnimation(const std::string& aAnimationName);
	void		DestroyAnimation(Animation* aAnimation);
private:
	AnimationFactory() = default;
	jsonWrapper::json myAnimationsJSON;
};