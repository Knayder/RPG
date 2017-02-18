#include "Scene.h"
#include "Game.h"

Scene::Scene()
{

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
