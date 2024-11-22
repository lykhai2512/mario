#pragma once
#include "GameState.h"
#include "AssetManager.h"
#include "Collision.h"

class PlayingState : public GameState{
private:
	std::vector<PlayableCharacter*>all_good_characters;
	std::vector<NonPlayableCharacter*>all_bad_characters;
	std::vector<Block*>all_blocks;
	std::vector<Item*>all_items;
	ID mapType;
	Collision collision;
	bool isMapCreated = false;
	
	void createMap();
	void update(sf::RenderWindow* window);
	void drawMap(sf::RenderWindow* window);
public:
	void execute(sf::RenderWindow* window);
};

