#include "gameobjects/Player.hpp"

Player::Player()
{
	texture.loadFromFile("data/characters/swordsman_test/SwordsMan_tex.png");

	factory.loadDragonBonesData("data/characters/swordsman_test/SwordsMan_ske.json");
	factory.loadTextureAtlasData("data/characters/swordsman_test/SwordsMan_tex.json", &texture);

	animationStateMap =
	{
		{idle, "steady"},
		{walking, "walk"},
		{sprinting, "walk2"},
		{flying, "jump"},
		{dying, "attack1"},
		{crying, "steady2"}
	};

	currentState = playerState::idle;
	previousState = playerState::idle;

	armatureDisplay = new dragonBones::SFMLArmatureDisplay("Swordsman");
	armatureDisplay->getAnimation()->play("steady");
	armatureDisplay->setPosition(sf::Transformable::getPosition());
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) currentState = playerState::flying;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) currentState = playerState::sprinting;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) currentState = playerState::crying;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) currentState = playerState::dying;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		armatureDisplay->getArmature()->setFlipX(true);
		if (previousState != walking && aniClck.getElapsedTime().asSeconds() > tlim)currentState = playerState::walking;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		armatureDisplay->getArmature()->setFlipX(false);
		if (previousState != walking && aniClck.getElapsedTime().asSeconds() > tlim)currentState = playerState::walking;
	}
	else if (aniClck.getElapsedTime().asSeconds() > tlim) currentState = playerState::idle;

	armatureDisplay->setPosition(sf::Transformable::getPosition());

	animationStateResolver();
	factory.update(deltaTime);

	previousState = currentState;
}

sf::FloatRect Player::getGlobalBounds()
{
	return armatureDisplay->getBoundingBox();
}

void Player::render(sf::RenderTarget& window)
{
	window.draw(*armatureDisplay);
}

void Player::animationStateResolver()
{
	if (currentState != previousState)
	{
		armatureDisplay->getAnimation()->play(animationStateMap.at(currentState));
		//armatureDisplay->getAnimation()->fadeIn(animationStateMap.at(currentState));
		aniClck.restart().asSeconds();
		tlim = armatureDisplay->getAnimation()->getState(animationStateMap.at(currentState))->_duration;
	}
	else return;
}