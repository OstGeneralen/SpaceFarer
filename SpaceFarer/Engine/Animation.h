#pragma once
#include <vector>
#include "SFML\Graphics\Sprite.hpp"

struct Frame;

namespace sf
{
	class RenderWindow;
	class Texture;
	class IntRect;
}

class Animation
{
public:  
	Animation() = default;
	Animation(sf::Texture* aTexture);
	void AddFrame(const sf::IntRect& aRect, float aTime);
	void Play();
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