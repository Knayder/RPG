#include "Game.h"


Game::Game() :
	status(Initializing),
	window(sf::VideoMode(1280,720), "Title", sf::Style::Close)
{
	TextureManager::load("grass", "data/grass.png");
	TextureManager::load("player", "data/player.png");
	currentScene = new Scene();
}


Game::~Game(){
	delete currentScene;
}


void Game::run(){
	/*Clock*/
	sf::Clock clock;
	float deltaTime = 1.f / 60.f;

	

	while (getStatus() != CleaningUp) {
		float startTime = clock.getElapsedTime().asSeconds();

		input();

		window.clear(sf::Color(37, 37, 48));
		/*******/

		currentScene->update(deltaTime);

		window.draw(*currentScene);

		/*******/

		window.display();

		deltaTime = clock.getElapsedTime().asSeconds() - startTime;
		/*Temporary FPS meter in windows title*/
		window.setTitle(sf::String("FPS:" + std::to_string((int)(1 / deltaTime))));
	}
}

void Game::input(){
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			status = CleaningUp;
	}
}


