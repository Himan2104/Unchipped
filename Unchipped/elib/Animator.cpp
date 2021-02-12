
#include "Animator.hpp"

util::Animator::Animator(sf::Texture& texture, sf::Vector2f FrameSize, float switchTime) : switchTime(switchTime), frameSize(FrameSize)
{
	totalFrames = texture.getSize().x / FrameSize.x;
	totalStates = texture.getSize().y / FrameSize.y;
	currentFrame = 0;
	animationClock.restart().asSeconds();

	currentFrameRect.width = FrameSize.x;
	currentFrameRect.height = FrameSize.y;
}

util::Animator::~Animator()
{
}

void util::Animator::update(sf::Sprite& sprite, int currentState)
{
	if (animationClock.getElapsedTime().asSeconds() >= switchTime)
	{
		if (currentFrame == totalFrames-1) currentFrame = 0;
		else currentFrame++;
		animationClock.restart().asSeconds();
	}

	currentFrameRect.left = currentFrame * frameSize.x;
	currentFrameRect.top = currentState * frameSize.y;

	sprite.setTextureRect(currentFrameRect);
}
