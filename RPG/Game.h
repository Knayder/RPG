#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Player.h"

enum Status {
	Initializing,
	Running,
	Paused,
	CleaningUp
};

//class Scene;

class Game final
{
public:
	/*Delete constr. and oper.*/
	Game(const Game &) = delete;
	void operator = (const Game &) = delete;

	/*Destructor*/
	~Game();

	/*Single instance getter*/
	inline static Game & Instance() {
		static Game instance;
		return instance;
	}

	/*Getters*/
	Status getStatus() {
		return status;
	}
	sf::RenderWindow &getWindow() {
		return window;
	}

	/*Run, location of game's main loop*/
	void run();
	
	
private:
	/*Private constructor*/
	Game();

	/*Input manager*/
	void input();

	/*Objects*/
	Status status;
	sf::RenderWindow window;
	Scene *currentScene;
};

