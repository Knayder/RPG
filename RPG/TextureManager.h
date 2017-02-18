#pragma once
#include <unordered_map>
#include <SFML\Graphics.hpp>


class TextureManager final
{
public:
	/*Delete constr. and oper.*/
	TextureManager(TextureManager &) = delete;
	void operator=(TextureManager &) = delete;
	~TextureManager();

	/*Instance*/
	static TextureManager & Instance() {
		static TextureManager instance;
		return instance;
	}

	/*Typedef*/
	typedef std::unordered_map<std::string, sf::Texture *> TextureContainer;

	/*Static Functions*/

	/*Load given file to container
	Return added texture*/
	sf::Texture * load(std::string name, std::string path);
	
	/*Return given texture with given index*/
	static sf::Texture * get(std::string name);

	/*Remove given texture with given index
	Return ture if removed succesful
	Return false if texture doesn't exist*/
	static bool remove(std::string name);

	/*Remove everything from container*/
	static void clean();


private:
	TextureManager(){}
	/*Def text. cont.*/
	TextureContainer textureContainer;
};

