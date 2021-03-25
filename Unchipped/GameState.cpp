
#include "GameState.hpp"

GameState::GameState()
{
	playerSpeed = 150.0f;
	inAir = true;
}

GameState::~GameState()
{
}

void GameState::initialize()
{
	map.load("data/maps/level_00.tmx");

	const auto& layers = map.getLayers();
	const auto& objLayer = layers[2]->getLayerAs<tmx::ObjectGroup>();

	player.setSize(sf::Vector2f(64.0f, 200.0f));
	player.setFillColor(sf::Color::Magenta);
	util::centerOrigin(player);
	//player.setPosition(map_loader.SpawnPoint().left + map_loader.SpawnPoint().width / 2.0f, map_loader.SpawnPoint().top + map_loader.SpawnPoint().height / 2.0f);

	camera.setSize(sf::Vector2f(1920.0f, 1080.0f));
	camera.setCenter(player.getPosition());


	for (auto& obj : objLayer.getObjects())
	{
		if (obj.getType() == "SpawnPoint") player.setPosition(obj.getAABB().left + obj.getAABB().width / 2.0f, obj.getAABB().top + obj.getAABB().height / 2.0f);
		else if (obj.getType() == "platform") colliders.push_back(sf::FloatRect(obj.getAABB().left, obj.getAABB().top, obj.getAABB().width, obj.getAABB().height));
		else if (obj.getType() == "triggers") triggers.push_back(sf::FloatRect(obj.getAABB().left, obj.getAABB().top, obj.getAABB().width, obj.getAABB().height));
	}

	baseBG.setup(map, 0);
	baseMAP.setup(map, 1);
	
}

void GameState::eventHandler(sf::Event& event, const sf::RenderWindow& window)
{
	if (event.type == sf::Event::KeyReleased)
		if (event.key.code == sf::Keyboard::Space && jumpDelayClock.getElapsedTime().asMilliseconds() > 500)
		{
			inAir = true;
			jumpDelayClock.restart().asMilliseconds();
		}
}

void GameState::update(float delTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) player.move(0.0f, -playerSpeed * delTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) player.move(0.0f, playerSpeed * delTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) player.move(-playerSpeed * delTime, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) player.move(playerSpeed * delTime, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) StateMachine::access()->changeState(new MainMenu());

	camera.setCenter(player.getPosition());

	if ((camera.getCenter().x - camera.getSize().x / 2) < 0) camera.move(sf::Vector2f(camera.getSize().x / 2 - player.getPosition().x, 0));
	if ((camera.getCenter().y - camera.getSize().y / 2) < 0) camera.move(sf::Vector2f(0, camera.getSize().y / 2 - player.getPosition().y));
	if ((camera.getCenter().x + camera.getSize().x / 2) > baseBG.getGlobalBounds().width) camera.move(sf::Vector2f(baseBG.getGlobalBounds().width - (camera.getCenter().x + camera.getSize().x / 2), 0));
	if ((camera.getCenter().y + camera.getSize().y / 2) > baseBG.getGlobalBounds().height) camera.move(sf::Vector2f(0, baseBG.getGlobalBounds().height - (camera.getCenter().y + camera.getSize().y / 2)));

	

	if (inAir)
	{
		if (jumpDelayClock.getElapsedTime().asMilliseconds() > 500)
			player.move(0.0f, playerSpeed * delTime);
		else player.move(0.0f, -playerSpeed * 3 * delTime);
	}

	for (auto& currentObj : colliders)
	{
		if (currentObj.intersects(player.getGlobalBounds()))
		{
			if (player.getPosition().y < currentObj.top) player.move(0.0f, -playerSpeed * delTime);
			if (player.getPosition().y > currentObj.top + currentObj.height) player.move(0.0f, playerSpeed * delTime);
			if (player.getPosition().x < currentObj.left) player.move(-playerSpeed * delTime, 0.0f);
			if (player.getPosition().x > currentObj.left + currentObj.width) player.move(playerSpeed * delTime, 0.0f);
		}
		if (currentObj.contains(sf::Vector2f(player.getGlobalBounds().left + player.getGlobalBounds().width / 2.0f, player.getGlobalBounds().top + player.getGlobalBounds().height)))
			inAir = false;
	}
}

void GameState::draw(sf::RenderTarget& target)
{
	target.setView(camera);

	target.draw(baseBG);
	target.draw(baseMAP);
	
	target.draw(player);
}

