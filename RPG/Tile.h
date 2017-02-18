#pragma once

#include "Entity.h"
#include "TextureManager.h"

class Tile : public Entity
{
public:
	Tile(std::string name, sf::Vector2f position = {0,0});

	sf::Sprite tile;

private:
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
};

