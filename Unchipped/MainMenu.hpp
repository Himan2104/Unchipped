#pragma once
#include<SFML/Graphics.hpp>
#include"State.hpp"
#include"StateMachine.hpp"
#include"AssetManager.hpp"
#include"elib/Button.hpp"
#include"elib/Animator.hpp"
#include"CreditsScreen.hpp"
#include"GameState.hpp"

class MainMenu : public State
{
public:
	MainMenu();
	~MainMenu();

	void initialize() override;
	void eventHandler(sf::Event& event, const sf::RenderWindow& window) override;
	void update(float delTime) override;
	void draw(sf::RenderTarget& target) override;

private:
	gui::Button PLAY, CREDITS, EXIT;

	sf::Text pressanykey;
	bool pak;

	sf::RectangleShape shadeoverlay;

	sf::Sprite logo;

	sf::Sprite bg;

	float lDelay;

	sf::Sound click;

	sf::Sprite ligt;
	int animGroup;
	bool drawLight;
	int currentAnimationState;

	sf::Clock aClock;
	sf::Clock delayTimer;

	void lAnima(float switchTime);

	

};

