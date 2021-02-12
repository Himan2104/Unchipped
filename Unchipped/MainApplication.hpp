#pragma once
#include"SFML/Graphics.hpp"

class MainApplication
{
public:
	MainApplication(sf::VideoMode Vmode, std::string name = "NewWindow");
	~MainApplication();

	void run();

	void closeApplication();

private:
	sf::VideoMode Vmode;
	sf::RenderWindow window;

	sf::Clock mainClock;
	float delTime;
};

