#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable
{
public:
	Entity();
	virtual void update(const float &deltaTime) {}
private:
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const {}
};

