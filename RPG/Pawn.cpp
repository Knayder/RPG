#include "Pawn.h"



Pawn::Pawn(PawnController *toSet) :
	controller(nullptr)
{
	if (toSet != nullptr && toSet->setOwner(this))
		controller = toSet;
}



bool Pawn::resetController(PawnController * newController){
	if (controller != newController) {
		delete controller;
		controller = newController;
		controller->setOwner(this);
		return true;
	}
	else
		return false;
}

void Pawn::update(const float & deltaTime){
	if (controller != nullptr)
		controller->update(deltaTime);
}

PawnController::PawnController() :
	owner(nullptr)
{
}

bool PawnController::setOwner(Pawn * newOwner)
{
	if (owner == nullptr) {
		owner = newOwner;
		return true;
	}
	else
		return false;
}
