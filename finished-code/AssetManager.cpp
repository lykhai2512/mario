
#include "AssetManager.h"
#include <cassert>

AssetManager* AssetManager::ONE_AND_ONLY = 0;


AssetManager::AssetManager()
{
	assert(this->ONE_AND_ONLY == 0);
	this->ONE_AND_ONLY = this;
}


sf::Texture& AssetManager::getTexture(std::string filename)
{
	auto& it = ONE_AND_ONLY->textures.find(filename);
	if (it == ONE_AND_ONLY->textures.end())
	{
		sf::Texture a;
		a.loadFromFile(filename);
		ONE_AND_ONLY->textures[filename] = a;
		return ONE_AND_ONLY->textures[filename];
	}
	else return it->second;
}

sf::Font& AssetManager::getTypeFace(std::string filename)
{
	auto& it = ONE_AND_ONLY->fonts.find(filename);
	if (it == ONE_AND_ONLY->fonts.end())
	{
		sf::Font a;
		a.loadFromFile(filename);
		ONE_AND_ONLY->fonts[filename] = a;
		return ONE_AND_ONLY->fonts[filename];
	}
	else return it->second;
}

AssetManager MNG;