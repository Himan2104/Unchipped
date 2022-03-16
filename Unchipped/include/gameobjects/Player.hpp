#pragma once
#include<SFML/Graphics.hpp>
#include"sfdb/SFMLFactory.h"
#include"sfdb/SFMLArmatureDisplay.h"


enum playerState
{
	walking, sprinting, flying, dying, crying, idle
};

class Player : public sf::Transformable
{
public:
	Player();
	~Player();

	void update(float deltaTime);

	sf::FloatRect getGlobalBounds();

	void render(sf::RenderTarget& window);

private:
	playerState currentState;
	playerState previousState;

	dragonBones::SFMLFactory factory;

	sf::Texture texture;

	dragonBones::SFMLArmatureDisplay* armatureDisplay;

	std::map<playerState, std::string> animationStateMap;

	sf::Clock aniClck;
	float tlim;
	void animationStateResolver();
};

