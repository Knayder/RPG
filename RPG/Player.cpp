#include "Player.h"





Player::Player() :
	Pawn(new PlayerController()),
	shape(sf::Vector2f(50,50))
{

}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(shape, states);
}


void PlayerController::update(const float & deltaTime) {
	sf::Vector2f offset(1280 / 2, 720 / 2);
	offset -= owner->getPosition();
	float c = std::sqrt(offset.x*offset.x + offset.y*offset.y);
	offset.x /= c;
	offset.y /= c;
	velocity += offset;
	owner->move(velocity*deltaTime);
}
