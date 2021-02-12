#pragma once
#include<SFML/Graphics.hpp>

namespace util
{
	class Animator
	{
	public:
		Animator(sf::Texture& texture, sf::Vector2f FrameSize, float switchTime);
		~Animator();

		void update(sf::Sprite& sprite, int currentState);

	private:
		int totalFrames, totalStates;
		int currentFrame, currentState;
		float switchTime;

		sf::Vector2f frameSize;

		sf::IntRect currentFrameRect;

		sf::Clock animationClock;
	};
}