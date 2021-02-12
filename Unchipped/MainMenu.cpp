#include "MainMenu.hpp"
#include<iostream>

MainMenu::MainMenu() : 
	PLAY(AssetManager::access()->getFont("yooy"), sf::Vector2f(256.0f, 64.0f), "PLAY"),
	CREDITS(AssetManager::access()->getFont("yooy"), sf::Vector2f(256.0f, 64.0f), "CREDITS"),
	EXIT(AssetManager::access()->getFont("yooy"), sf::Vector2f(256.0f, 64.0f), "EXIT")
{
	currentAnimationState = 0;
	animGroup = 0;
	drawLight = true;
	aClock.restart().asSeconds();
	delayTimer.restart().asSeconds();
	pak = false;
	lDelay = float(std::rand() % 2 + 1);
}

MainMenu::~MainMenu()
{
}

void MainMenu::initialize()
{
	PLAY.setPosition(sf::Vector2f(960.0f, 540.0f));
	CREDITS.setPosition(sf::Vector2f(960.0f, 640.0f));
	EXIT.setPosition(sf::Vector2f(960.0f, 740.0f));
	/*
	PLAY.setFunction([]() {StateMachine::access()->changeState(new GameState()); });
	CREDITS.setFunction([]() {StateMachine::access()->changeState(new CreditsScreen()); });
	EXIT.setFunction([]() { std::cout << "exit"; });
	*/

	

	pressanykey.setString("Press ENTER to continue...");
	pressanykey.setFont(AssetManager::access()->getFont("sjbadjkw"));
	pressanykey.setCharacterSize(40);
	util::eUtil::centerOrigin(pressanykey);
	pressanykey.setPosition(960.0f, 960.0f);

	shadeoverlay.setSize(sf::Vector2f(1920, 1080));
	shadeoverlay.setFillColor(sf::Color(0, 0, 0, 175));

	click.setBuffer(AssetManager::access()->getSFX("sahjdsk"));

	bg.setTexture(AssetManager::access()->getTexture("mm_bg"));

	logo.setTexture(AssetManager::access()->getTexture("mm_title"));
	util::eUtil::centerOrigin(logo);
	logo.setPosition(960.0f, 200.0f);

	ligt.setTexture(AssetManager::access()->getTexture("lightning"));
	ligt.setTextureRect(sf::IntRect(0, 0, 400, 400));
	ligt.setOrigin(200.0f, 200.0f);
	ligt.setPosition(200.0f, 200.0f);

	
}

void MainMenu::eventHandler(sf::Event& event, const sf::RenderWindow& window)
{
	/*PLAY.EventHandler(event, window);
	CREDITS.EventHandler(event, window);
	EXIT.EventHandler(event, window);*/
	if (PLAY.isClicked(window))
	{
		click.play();
		StateMachine::access()->changeState(new GameState());
	}
	else if (CREDITS.isClicked(window))
	{
		click.play();
		StateMachine::access()->changeState(new CreditsScreen());
	}
	else if (EXIT.isClicked(window)) exit(0);
}

void MainMenu::update(float delTime)
{

	if (!pak)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) pak = true;
	}
	
	//std::cout << "dL : " << drawLight << std::endl;
	if (delayTimer.getElapsedTime().asSeconds() > lDelay)
	{
		drawLight = true;
		delayTimer.restart().asSeconds();
		lDelay = float(std::rand() % 2 + 1);
	}

	lAnima(0.02f);
}

void MainMenu::draw(sf::RenderTarget& target)
{
	target.setView(target.getDefaultView());
	target.draw(bg);
	target.draw(logo);
	if (drawLight) target.draw(ligt);

	if (!pak) target.draw(pressanykey);
	else
	{
		target.draw(shadeoverlay);
		target.draw(logo);
		PLAY.render(target);
		CREDITS.render(target);
		EXIT.render(target);
	}
}

void MainMenu::lAnima(float switchTime)
{
	sf::IntRect rectTemp = ligt.getTextureRect();
	

	if (rectTemp.left < 3600 && drawLight)
	{
		if (aClock.getElapsedTime().asSeconds() > switchTime)
		{
			rectTemp.left += 400;
			ligt.setTextureRect(rectTemp);
			aClock.restart().asSeconds();
		}
	}
	else
	{
		animGroup = std::rand() % 5;
		drawLight = false; 
		int x = std::rand() % 1520 + 200;
		int y = std::rand() % 140 + 200;
		ligt.setPosition(x, y);
		ligt.setTextureRect(sf::IntRect(0, animGroup * 400, 400, 400));
	}
}




