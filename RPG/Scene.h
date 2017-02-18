#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.h"


class Scene : public sf::Drawable
{
public:
		/*Const. and Destr.*/
	Scene();
	~Scene();

		/*Typdefs*/
	typedef std::vector<Entity *> EntityContainer;
	
		/*Functions*/

	/*Calling every tick*/
	void update(const float &deltaTime);

	/*Add element to entityContainer*/
	bool add(Entity *toAdd);

	/*Check is given argument exists in entityContainer*/
	bool exists(Entity *isExists);

	/*Remove given argument from entityContainer*/
	bool remove(Entity *toRemove);


private:
		/*Override funcs.*/
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		/*Container def.*/
	EntityContainer entityContainer;
};

