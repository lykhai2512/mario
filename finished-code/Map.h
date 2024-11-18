
#pragma once
//#include "WorldObject.h"
//#include "Collision.h"
//#include "Animation.h"
#include "Block.h"
#include "AssetManager.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Map
{
public: // for now
	std::vector<std::vector<Block *>> elementPTRs;
	//std::vector<sf::Sprite> container;
public:
	Map(std::string filename); // passing in a file name. the map should be stored as a file, this eliminates hardcoding and allows user to change the maps
	// deallocate
	~Map();
	void debugPrint();
	void draw(sf::RenderWindow &tgt);
	sf::Vector2i getArea();
	std::vector<Block*>& operator[](int index)
	{
		if (index < 0 || index > this->elementPTRs.size())
			throw std::runtime_error("hey fuck you");
		return this->elementPTRs[index];
	}
};