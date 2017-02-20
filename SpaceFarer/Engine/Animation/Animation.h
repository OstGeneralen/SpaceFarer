#pragma once
#include <vector>
#include "SFML\Graphics\Sprite.hpp"

struct Frame
{
	float myTime = 0;
	sf::IntRect myRect = { 0,0,0,0 };
};

namespace sf
{
	class RenderWindow;
	class Texture;
}

class Animation
{
public:  
	Animation() = default;
	Animation(sf::Texture* aTexture);
	void AddFrame(const sf::IntRect& aRect, float aTime);
	void Play(bool aIsRepeating = false);
	void Update(float aDeltaTime);
	void Render(sf::RenderWindow& aGameWindow);

private:
	void ChangeFrame();
	bool myIsPlaying;
	bool myIsRepeat;
	sf::Texture* myTexture = nullptr;
	sf::Sprite myCurrentSprite;
	std::vector<Frame> myFrames;
	unsigned int myCurrentFrame;
	float myTimer;

};