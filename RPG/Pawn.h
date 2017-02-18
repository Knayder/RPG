#pragma once

#include "Entity.h"

class PawnController;

class Pawn : public Entity
{
public:
	/*Constr. and Destr.*/
	Pawn(PawnController *toSet);

	/*Reset controller*/
	bool resetController(PawnController *newController);

	virtual void update(const float &deltaTime) override;

private:
	/*Draw func.*/
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const {}

	/*Pointer to controller*/
	PawnController *controller;
};

class PawnController {
public:
	/*Constr.*/
	PawnController();

	/*Set Pawn as friend*/
	friend class Pawn;

	/*Base func. to override*/
	virtual void update(const float &deltaTime) {}

protected:
	/*Set controller's owner*/
	bool setOwner(Pawn *newOwner);

	/*Pointer to owner*/
	Pawn *owner;
};