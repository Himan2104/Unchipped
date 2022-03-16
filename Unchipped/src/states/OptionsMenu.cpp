#include"states/OptionsMenu.hpp"


OptionsMenu::OptionsMenu()
{
	Apply = new gui::Button(AssetManager::access()->getFont("con_font"), sf::Vector2f(256.0f, 64.0f), "Apply");
	fpsCap = new gui::TextBox(sf::Vector2f(128.0f, 32.0f), "FrameRateLimit");
	Sound = new gui::CheckBox(AssetManager::access()->getFont("con_font"), "Sound", 3.0f);
	Vol = new gui::Slider(std::make_pair<float, float>(0.0f, 100.0f));
}

OptionsMenu::~OptionsMenu()
{
}

void OptionsMenu::initialize()
{
	Apply->setPosition(sf::Vector2f(1820.0f, 980.0f));
	fpsCap->setPosition(sf::Vector2f(1920.0f/2.0f, 100.0f));
	Sound->setPosition(sf::Vector2f(1920.0f/2.0f, 300.0f));
	Vol->setPosition(sf::Vector2f(1920.0f / 2.0f, 500.0f));

	fpsCap->setFont(AssetManager::access()->getFont("con_font"));
}

void OptionsMenu::eventHandler(sf::Event& event, const sf::RenderWindow& window)
{
	//Apply.EventHandler(event, window);
	if (Apply->isClicked(window))
	{
		StateMachine::access()->changeState(new MainMenu());
		return;
	}
	if(fpsCap != nullptr) fpsCap->EventHandler(event, window);
	Sound->EventHandler(event, window);
	Vol->EventHandler(event, window);
}

void OptionsMenu::update(float delTime)
{
	Debug::log("SliderValue: " + std::to_string(Vol->getCurrentValue()));
}

void OptionsMenu::draw(sf::RenderTarget& target)
{
	Apply->render(target);
	fpsCap->render(target);
	Sound->render(target);
	Vol->render(target);
}
