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
	void					AddFrame(const sf::IntRect& aRect, float aTime);
	void					Play(const sf::Vector2f& aPosition, bool aIsRepeating = false);
	void					Update(float aDeltaTime);
	void					Render(sf::RenderWindow& aGameWindow);
	const bool				IsDone() const;

private:
	void					ChangeFrame();

	bool					myIsPlaying;
	bool					myIsRepeat;

	float					myTimer;
	unsigned int			myCurrentFrame;

	sf::Texture*			myTexture = nullptr;
	sf::Sprite				myCurrentSprite;
	std::vector<Frame>		myFrames;
};