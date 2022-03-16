#include <typeinfo>
#include "Core/MainApplication.hpp"
#include "Core/StateMachine.hpp"
#include "States/SplashScreen.hpp"

MainApplication::MainApplication(sf::VideoMode Vmode, std::string name)
{
	this->Vmode = Vmode;
	window.create(this->Vmode, name, sf::Style::Fullscreen);
	window.setFramerateLimit(0);

	AssetManager::access()->loadGlobalAssets();

	StateMachine::access()->changeState(new SplashScreen());
	
	_dd.setFont(AssetManager::access()->getFont("con_font"));
	_dd.setCharacterSize(12u);
	_dd.setPosition(5.0f, 5.0f);
}

MainApplication::~MainApplication()
{
}

void MainApplication::run()
{
	TimeKeeper::initializeTime();

	while (window.isOpen())
	{
		TimeKeeper::updateTime();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			StateMachine::access()->getActiveState()->eventHandler(event, window);
		}

		StateMachine::access()->getActiveState()->update(TimeKeeper::deltaTime());

		debugData = {1.0f/TimeKeeper::frameTime(),
		TimeKeeper::timeSinceStart(TimeKeeper::ClockType::Static),
		TimeKeeper::timeSinceStart(TimeKeeper::ClockType::Dynamic),
		TimeKeeper::getTimeScale(), typeid(*StateMachine::access()->getActiveState()).name()};

		_dd.setString(Debug::onScreenDebugData(debugData));

		window.clear();
		StateMachine::access()->getActiveState()->draw(window);
		_dd.setPosition(window.getView().getCenter() - sf::Vector2f(955.0f, 535.0f));
		window.draw(_dd);
		window.display();
	}
}

void MainApplication::closeApplication()
{
	window.close();
}
