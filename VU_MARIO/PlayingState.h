#pragma once
#include "GameState.h"
#include "AssetManager.h"
#include "Collision.h"
#include "View.h"

class PlayingState : public GameState{
private:
	int coin = 0;
	int lives = 10;
	int mapNum = 1;
	int time = 400;
	int score = 0;
	View *view;

	std::vector<PlayableCharacter*>all_playable_characters;
	std::vector<NonPlayableCharacter*>all_non_playable_characters;
	std::vector<Block*>all_blocks;
	std::vector<Item*>all_items;
	
	Collision collision;
	bool isMapCreated = false;
	
	
	void createMap();
	void update(sf::RenderWindow* window);
	void drawMap(sf::RenderWindow* window);
public:
	PlayingState();
	~PlayingState();
	
	void execute(sf::RenderWindow* window);
	void addCoin();
	void addScore();
	void decreaseLives();
	void changeMap();
	void restart();
	bool isActive();
};

