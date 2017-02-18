#include "Scene.h"
#include "Game.h"

Scene::Scene()
{
	for (float y = 0; y < (int)720 / 64; y++)
		for (float x = 0; x < (int)1280 / 64; x++) {
			Entity *tile = new Tile("grass", { 64.f * x, 64.f * y });
			add(tile);
		}
	int map[9][20] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	for (int y = 0; y < 9; y++)
		for (int x = 0; x < 20; x++)
			if (map[y][x] == 1) {
				Entity *tile = new Tile("player", { 64.f * x, 64.f * y });
				add(tile);
			}
	
}


Scene::~Scene()
{
	const unsigned int size = entityContainer.size();

	for (unsigned int i = 0u; i < size; ++i)
		delete entityContainer[i];
}

void Scene::update(const float & deltaTime){
	const unsigned int size = entityContainer.size();

	for (unsigned int i = 0u; i < size; ++i)
		entityContainer[i]->update(deltaTime);
}

bool Scene::add(Entity * toAdd) {
	if (toAdd != nullptr && !exists(toAdd))
		entityContainer.push_back(toAdd);
	else
		return false;
	return true;
}

bool Scene::exists(Entity * isExists) {
	return std::find(entityContainer.begin(), entityContainer.end(), isExists) != entityContainer.end();
}

bool Scene::remove(Entity * toRemove){
	if (exists(toRemove)) {
		auto iterator = std::find(entityContainer.begin(), entityContainer.end(), toRemove);
		if (iterator != entityContainer.end())
			entityContainer.erase(iterator);
		else
			return false;
	}
	else
		return false;

	return true;
}

void Scene::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	const unsigned int size = entityContainer.size();

	for (unsigned int i = 0u; i < size; ++i)
		Game::Instance().getWindow().draw(*(entityContainer[i]));
}
