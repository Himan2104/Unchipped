#pragma once
#include"core/State.hpp"
#include"core/StateMachine.hpp"
#include"states/MainMenu.hpp"
#include<sfeMovie/Movie.hpp>


class SplashScreen : public State
{
public:
	SplashScreen();
	~SplashScreen();

	void initialize() override;
	void eventHandler(sf::Event& event, const sf::RenderWindow& window) override;
	void update(float delTime) override;
	void draw(sf::RenderTarget& renderer) override;

private:
	
	sfe::Movie splash;

	sf::Clock delayClock;

	
};

