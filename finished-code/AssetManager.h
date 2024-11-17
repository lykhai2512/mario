#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<SFML/Graphics.hpp>

class Block;
class Item;
class Character;
enum class BlockType;
enum class ItemType;
enum class CharacterType;

enum class BlockType {
	none = -1,
	ground = 0,
	indestructible_brick = 1,
	base_brick = 2,
	brick = 3,
	vertical_pipe = 4,
	vertical_pipe_top = 5,
	horizontal_pipe = 6,
	bonus_brick = 7,
	small_tree = 8,
	big_tree = 9,
	mountain = 10,
	cloud = 11,
	castle = 12,
	flag = 13
};


enum class ItemType {
    none = -1,
    flower = 0,
    good_mushroom = 1,
    coin = 2,
    star = 3
};

enum class CharacterType {
    none = -1,
    Mario = 0,
    Luigi = 1
};

enum class EntityType{
	Block = 1,
	Item = 2,
	Character = 3
};

enum class MapType{
	map1 = 1,
	map2 = 2,
	map3 = 3,
	map4 = 4,
};

class AssetManager {
private:
	const std::string baseLink = "images/NotAnimation/Map";
	const int numOfMaps = 4;
	const std::string positionFile = "images/position";

	const std::vector<std::string>types = {"ground","indestructible_brick","base_brick",
	"brick","vertical_pipe","vertical_pipe_top","horizontal_pipe","bonus_brick",
	"small_tree","big_tree","mountain","cloud","castle","flag"};


	std::vector<std::vector<std::vector<sf::Vector2f>>>map;
	static AssetManager* instance;

	void readAnimationFile();
	void readPositionOfMap();

public:
	static AssetManager* getInstance();
	AssetManager();
	~AssetManager();
	void load();
	std::string getImage(MapType m_type,EntityType e_type,BlockType b_type = BlockType::none,ItemType i_type = ItemType::none,CharacterType c_type = CharacterType::none);
	std::vector<std::vector<sf::Vector2f>>getPosition(MapType m_type);
	std::vector<sf::Vector2f>getPosition(MapType m_type,EntityType e_type ,BlockType b_type = BlockType::none,ItemType i_type = ItemType::none,CharacterType c_item = CharacterType::none);
};


