#include "Tile.h"




Tile::Tile(std::string name, sf::Vector2f position)
{
	auto texture = TextureManager::get(name);
	tile.setTexture(*texture);
	tile.scale(64.f/texture->getSize().x, 64.f/texture->getSize().y);
	setPosition(position);
}



void Tile::draw(sf::RenderTarget & target, sf::RenderStates states) const{
	states.transform *= getTransform();
	target.draw(tile, states);
}
