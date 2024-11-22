#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<map>
#include<SFML/Graphics.hpp>

//read full animation, notanimation file
//do 1 times, put all block, get all size of them , read each of them into texture with float rect (not many)


enum class BlockID {
	big_castle = 1,
	ground = 2,
	bonus = 3,
	indestructible = 4,
	basebrick = 5,
	brick = 6,
	vertical_pipe = 7,
	vertical_pipe_top = 8,
	tree = 9,
	mountain = 10, 
	castle = 11,
	cloud = 12,
	fence = 13,
	flag = 14,
	palm = 15,
	stick = 16
};

enum class ItemID {
	coin_animation = 1,
	flower_animation = 2,
	mushroom_animation = 3,
	star_animation = 4,
};


enum class NonPlayableCharacterID {
	boss = 1,
	goomba = 2,
	crushed_goomba = 3,
	cactus = 4,
	turtle = 5,
	turtle_shell = 6,
};


enum class PlayableCharacterType {
	small_mario = 1,
	disappear_small_mario = 2,
	small_fire_mario = 3,
	small_super_mario = 4,
	big_mario = 5,
	big_fire_mario = 6,
	big_super_mario = 7,
	small_luigi = 8,
	big_luigi = 9,
	big_fire_luigi = 10,
	big_super_luigi = 11,
	transform = 12
};

class AssetManager {
private:

	const std::vector<sf::Vector2f>BlockSize = {
		sf::Vector2f(296.f,352.f),
		sf::Vector2f(32.f,32.f),
		sf::Vector2f(32.f,32.f),
		sf::Vector2f(32.f,32.f),
		sf::Vector2f(32.f,32.f),
		sf::Vector2f(32.f,32.f),
		sf::Vector2f(56.f,34.f),
		sf::Vector2f(64.f,30.f),
		sf::Vector2f(64.f,32.f),
		sf::Vector2f(96.f,38.f),
		sf::Vector2f(160.f,160.f),
		sf::Vector2f(64.f,48.f),
		sf::Vector2f(64.f,32.f),
		sf::Vector2f(32.f,32.f),
		sf::Vector2f(62.f,70.f),
		sf::Vector2f(16.f,304.f),};


	const int NUMBER_OF_BLOCKS = 16;

	const std::vector<std::string>FILE = {
		"../images/blocks.png",
		"../images/items.png",
		"../images/playable_characters.png",
		"../images/nonPlayable_characters.png",
	};


	std::vector<sf::Sprite*> blocks;
	std::vector<std::pair<sf::Texture*,int>> items;
	std::vector<std::pair<sf::Texture*,int>> playable_characters;
	std::vector<std::pair<sf::Texture*,int>> nonplayable_characters;


	const float gravity = 10.f;

	static AssetManager* instance;

	void load();
	void loadBlocks();
	void loadItems();
	void loadNonPlayableCharacters();
	void loadPlayableCharacters();
public:
	static AssetManager* getInstance();
	AssetManager();
	~AssetManager();

};




