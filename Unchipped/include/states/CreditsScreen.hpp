#pragma once
#include<SFML/Graphics.hpp>
#include<sfml/Audio.hpp>
#include"core/State.hpp"
#include"core/AssetManager.hpp"
#include"core/StateMachine.hpp"
#include<fstream>
#include"core/Utility.hpp"


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

