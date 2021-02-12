#pragma once
#include<SFML/Graphics.hpp>
#include"State.hpp"
#include"StateMachine.hpp"
#include"AssetManager.hpp"
#include"MainMenu.hpp"
#include"CreditsScreen.hpp"
#include"SplashScreen.hpp"
#include"eUtil.hpp"
#include"SFMLOrthogonalLayer.hpp"

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

	sf::RectangleShape player;

	float playerSpeed;

	sf::View camera;

	std::vector<sf::FloatRect> colliders, triggers;

	MapLayer baseBG, baseMAP;

	sf::Clock jumpDelayClock;

	bool inAir;
};

