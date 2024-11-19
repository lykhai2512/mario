#pragma once
#include "GameState.h"
#include "WorldObject.h"
#include "AssetManager.h"

class PlayingState : public GameState{
private:
	std::vector<WorldObject*>all_good_characters;
	std::vector<WorldObject*>all_bad_characters;
	std::vector<WorldObject*>all_blocks;
	std::vector<WorldObject*>all_items;
	ID mapType;
	bool isMapCreated = false;
	void createMap();
	void update(sf::RenderWindow* window);
	void drawMap(sf::RenderWindow* window);
public:
	void execute(sf::RenderWindow* window);
};

