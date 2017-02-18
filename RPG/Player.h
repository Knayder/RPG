#pragma once

#include "Pawn.h"
#include "TextureManager.h"

class PlayerController;

class Player : public Pawn
{
	sf::Sprite player;
	
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
public:
	Player();
};


class PlayerController : public PawnController
{
public:
	PlayerController();
	
	virtual void update(const float &deltaTime) override;
};
