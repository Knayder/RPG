#pragma once

#include "Pawn.h"

class PlayerController;

class Player : public Pawn
{
	sf::RectangleShape shape;
	
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
public:
	Player();
};


class PlayerController : public PawnController
{
	sf::Vector2f velocity;
public:
	PlayerController():
		velocity(300,0)
	{}
	
	virtual void update(const float &deltaTime) override;
};
