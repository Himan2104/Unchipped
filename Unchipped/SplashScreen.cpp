
#include "SplashScreen.hpp"
#include "eUtil.hpp"

SplashScreen::SplashScreen()
{
	
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::initialize()
{
	splash.openFromFile("data/videos/Main_1.mov");

	splash.fit(0, 0, 1920, 1080);
	splash.play();
	delayClock.restart().asSeconds();
}

void SplashScreen::eventHandler(sf::Event& event, const sf::RenderWindow& window)
{

}

void SplashScreen::update(float delTime)
{
	splash.update();

	if (delayClock.getElapsedTime().asSeconds() > 10.0f) StateMachine::access()->changeState(new MainMenu);
}

void SplashScreen::draw(sf::RenderTarget& renderer)
{
	renderer.setView(renderer.getDefaultView());
	renderer.draw(splash);

}
