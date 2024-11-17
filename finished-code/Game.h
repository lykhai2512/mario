#pragma once
#include "WorldObject.h"


class Game {
private:
	std::vector<WorldObject*>all_objects;
	MapType map_type;

	void loadMap();
	void draw(sf::RenderWindow* window);
public:
	void start(sf::RenderWindow* window);
	~Game();
};