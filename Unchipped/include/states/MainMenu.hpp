#pragma once
#include<SFML/Graphics.hpp>
#include<sfeMovie/Movie.hpp>
#include"core/TimeKeeper.hpp"
#include"core/State.hpp"
#include"core/StateMachine.hpp"
#include"core/AssetManager.hpp"
#include"elib/Button.hpp"
#include"elib/Animator.hpp"
#include"core/Utility.hpp"
#include"core/Debug.hpp"
#include"states/CreditsScreen.hpp"
#include"states/GameState.hpp"
#include"states/OptionsMenu.hpp"

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
	gui::Button PLAY, CREDITS, OPTIONS, EXIT;


	sfe::Movie MenuBG;

	sf::Text pressanykey;
	bool pak;

	sf::RectangleShape shadeoverlay;
	float overlayalpha;

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

