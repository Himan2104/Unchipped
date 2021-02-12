#pragma once
#include<SFML/Graphics.hpp>
#include<sfml/Audio.hpp>
#include"State.hpp"
#include"AssetManager.hpp"
#include"StateMachine.hpp"
#include<fstream>
#include"eUtil.hpp"


class CreditsScreen : public State
{
public:
	CreditsScreen();
	~CreditsScreen();


	void initialize() override;
	void eventHandler(sf::Event& event, const sf::RenderWindow& window) override;
	void update(float delTime) override;
	void draw(sf::RenderTarget& target) override;


private:
	sf::Sprite creds;

	sf::Sprite banner;

	sf::Music bgMusic;
};

