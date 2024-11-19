#pragma once
#include<iostream>
#include<vector>
#include<map>
#include "Block.h"
#include "Item.h"
#include "Character.h"


class AssetManager {
private:
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;
	static AssetManager* ONE_AND_ONLY;
public:
	AssetManager();
	static sf::Texture& getTexture(std::string filename);
	static sf::Font& getTypeFace(std::string filename);
};

