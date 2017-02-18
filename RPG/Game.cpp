#include "Game.h"

Game::Game() :
	status(Initializing),
	window(sf::VideoMode(1280,720), "Title", sf::Style::Close),
	currentScene(new Scene())
{
	/*Load textures to TextureManager*/
	//To do.
}


Game::~Game(){
	delete currentScene;
}


void Game::run(){
	/*Clock*/
	sf::Clock clock;
	float deltaTime = 1.f / 60.f;

	Entity *player = new Player();
	currentScene->add(player);

	while (getStatus() != CleaningUp) {
		deltaTime *= 50;
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


