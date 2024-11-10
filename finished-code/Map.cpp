#include "Map.h"

Map::Map()
{
}

Map::~Map()
{
	for (WorldObject* object : allObjects)
		delete object;
}

void Map::draw(sf::RenderWindow* window, MapType type)
{
	switch (type)
	{
	case MapType::Nature:
		
		break;
	case MapType::Cave:
		break;
	case MapType::Fire:
		break;
	default:
		break;
	}
}
