#include "TextureManager.h"

TextureManager::~TextureManager(){
	TextureManager & instance = Instance();
	for (auto it : instance.textureContainer)
		delete (it.second);
}

sf::Texture * TextureManager::load(std::string name, std::string path){
	sf::Texture *texture = TextureManager::get(name);
	
	if (texture == nullptr) {
		texture = new sf::Texture();
		texture->loadFromFile(path);
		textureContainer[name] = texture;
	}
	else
		texture->loadFromFile(path);

	return texture;
}

sf::Texture * TextureManager::get(std::string name){
	TextureManager & instance = Instance();
	auto textureIt = instance.textureContainer.find(name);
	if (textureIt == instance.textureContainer.end())
		return nullptr;
	return textureIt->second;
}

bool TextureManager::remove(std::string name){
	TextureManager & instance = Instance();
	auto textureIt = instance.textureContainer.find(name);
	if (textureIt != instance.textureContainer.end()) {
		delete (textureIt->second);
		instance.textureContainer.erase(textureIt);
		return true;
	}
	return false;
}

void TextureManager::clean(){
	TextureManager & instance = Instance();
	for (auto it : instance.textureContainer)
		delete (it.second);
	instance.textureContainer.clear();
}
