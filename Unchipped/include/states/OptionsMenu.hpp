#pragma once
#include<SFML/Graphics.hpp>
#include"core/State.hpp"
#include"core/StateMachine.hpp"
#include"core/AssetManager.hpp"
#include"elib/Button.hpp"
#include"elib/TextBox.hpp"
#include"elib/CheckBox.hpp"
#include"elib/Slider.hpp"
#include"core/Utility.hpp"
#include"core/Debug.hpp"
#include"states/CreditsScreen.hpp"
#include"states/GameState.hpp"


class OptionsMenu : public State
{
public:
	OptionsMenu();
	~OptionsMenu();

	void initialize() override;
	void eventHandler(sf::Event& event, const sf::RenderWindow& window) override;
	void update(float delTime) override;
	void draw(sf::RenderTarget& target) override;

private:
	gui::Button* Apply;
	gui::TextBox* fpsCap;
	gui::CheckBox* Sound;
	gui::Slider* Vol;

};

