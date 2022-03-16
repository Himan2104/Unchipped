#pragma once
#include<SFML/Graphics.hpp>
#include"core/State.hpp"
#include"core/StateMachine.hpp"
#include"core/AssetManager.hpp"
#include"states/MainMenu.hpp"
#include"core/Utility.hpp"
#include"core/SFMLOrthogonalLayer.hpp"
#include"gameobjects/Player.hpp"


class GameState : public State
{
public:
	GameState();
	~GameState();

	void initialize() override;
	void eventHandler(sf::Event& event, const sf::RenderWindow& window) override;
	void update(float delTime) override;
	void draw(sf::RenderTarget& target) override;

private:
	tmx::Map map;

	Player* player;

	float playerSpeed;

	sf::View camera;

	std::vector<sf::FloatRect> colliders, triggers;

	MapLayer baseBG, baseMAP;

	sf::Clock jumpDelayClock;

	bool inAir;
};

