
#include "CreditsScreen.hpp"
#include<iostream>
#include"MainMenu.hpp"

CreditsScreen::CreditsScreen()
{
}

CreditsScreen::~CreditsScreen()
{
}

void CreditsScreen::initialize()
{
    banner.setTexture(AssetManager::access()->getTexture("spsc_banner"));

    creds.setTexture(AssetManager::access()->getTexture("spsc_creds"));
    util::centerOrigin(creds);
    creds.setPosition(960,3080);

    bgMusic.openFromFile(AssetManager::access()->getMusic("tresh"));
  
    bgMusic.play();
}

void CreditsScreen::eventHandler(sf::Event& event, const sf::RenderWindow& window)
{
}

void CreditsScreen::update(float delTime)
{
    creds.move(0, -65.0f * delTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || 
        creds.getPosition().y + creds.getGlobalBounds().height/2.0f < 0.0f) 
            StateMachine::access()->changeState(new MainMenu());

}

void CreditsScreen::draw(sf::RenderTarget& target)
{
    target.setView(target.getDefaultView());
    target.draw(creds);
    target.draw(banner);
}
