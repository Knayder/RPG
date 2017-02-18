#include "Player.h"





Player::Player() :
	Pawn(new PlayerController())
{
	player.setTexture(*(TextureManager::get("player")));
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(player, states);
}


PlayerController::PlayerController()
{
}

void PlayerController::update(const float & deltaTime) {
	owner->rotate(10*deltaTime);
}
