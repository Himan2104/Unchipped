#pragma once
#include"SFML/Graphics.hpp"
#include"Debug.hpp"
#include"TimeKeeper.hpp"

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

	onScreenDD debugData;
	sf::Text _dd;
};

