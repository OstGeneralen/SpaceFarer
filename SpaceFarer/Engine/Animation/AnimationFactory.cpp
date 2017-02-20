#include "AnimationFactory.h"
#include <fstream>
#include "Animation.h"
#include "..\..\TextureBank.h"

AnimationFactory & AnimationFactory::GetInstance()
{
	static AnimationFactory* instance = new AnimationFactory();
	return *instance;
}

void AnimationFactory::Init(const std::string & aAnimationsJson)
{
	std::ifstream instream(aAnimationsJson);
	myAnimationsJSON << instream;
}

Animation * AnimationFactory::GetAnimation(const std::string & aAnimationName)
{
	jsonWrapper::json animationData = myAnimationsJSON[aAnimationName];

	
	Animation* animation = new Animation(GET_TEXTURE(animationData["texture"].get<std::string>()));
	int width = animationData["width"];
	int height = animationData["height"];
	
	jsonWrapper::json framesData = animationData["frames"];
	
	for (auto iterator = framesData.begin(); iterator != framesData.end(); ++iterator)
	{
		sf::IntRect tempRect;
		tempRect.left = (*iterator)[0];
		tempRect.top = (*iterator)[1];
		tempRect.width = width;
		tempRect.height = height;

		animation->AddFrame(tempRect, animationData["time"]);
	}
	
	return animation;

}

void AnimationFactory::DestroyAnimation(Animation * aAnimation)
{
	delete aAnimation;
	aAnimation = nullptr;
}
