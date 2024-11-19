#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<map>
#include<SFML/Graphics.hpp>


enum class ID {
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
	flag = 13,
	flower = 14,
	good_mushroom = 15,
	coin = 16,
	star = 17,
	Mario = 18,
	Luigi = 19,
	Item = 21,
	Character = 22,
	map1 = 23,
	map2 = 24,
	map3 = 25,
	map4 = 26,
};


class AssetManager {
private:

	const std::vector<sf::Vector2f>size = {
		sf::Vector2f(50.f,50.f),
		sf::Vector2f(50.f,50.f),
		sf::Vector2f(50.f,50.f),
		sf::Vector2f(50.f,50.f),
		sf::Vector2f(100.f,50.f),
		sf::Vector2f(150.f,50.f),
		sf::Vector2f(100.f,150.f),
		sf::Vector2f(50.f,50.f),
		sf::Vector2f(80.f,80.f),
		sf::Vector2f(100.f,100.f),
		sf::Vector2f(100.f,50.f),
		sf::Vector2f(100.f,50.f),
		sf::Vector2f(300.f,300.f),
		sf::Vector2f(50.f,50.f),
		sf::Vector2f(50.f,50.f),
		sf::Vector2f(50.f,50.f),
		sf::Vector2f(50.f,50.f),
		sf::Vector2f(50.f,50.f),
		sf::Vector2f(50.f,50.f),
		sf::Vector2f(50.f,50.f),
		sf::Vector2f(50.f,50.f),
		sf::Vector2f(50.f,50.f),
		sf::Vector2f(50.f,50.f),
		sf::Vector2f(50.f,50.f),
		sf::Vector2f(50.f,50.f),
		sf::Vector2f(50.f,50.f),
		sf::Vector2f(50.f,50.f),
	};

	const std::vector<std::string>file = {
		"../images/NotAnimation/ground.png",
		"../images/NotAnimation/indestructible_brick.png",
		"../images/NotAnimation/base_brick.png",
		"../images/NotAnimation/brick.png",
		"../images/NotAnimation/vertical_pipe.png",
		"../images/NotAnimation/vertical_pipe_top.png",
		"../images/NotAnimation/horizontal_pipe.png",
		"../images/NotAnimation/bonus_brick.png",
		"../images/NotAnimation/small_tree.png",
		"../images/NotAnimation/big_tree.png",
		"../images/NotAnimation/mountain.png",
		"../images/NotAnimation/cloud.png",
		"../images/NotAnimation/castle.png",
		"../images/NotAnimation/flag.png",
		"../images/NotAnimation/flower.png",
		"../images/NotAnimation/good_mushroom.png",
		"../images/NotAnimation/coin.png",
		"../images/NotAnimation/star.png",
		"../images/NotAnimation/Mario.png",
		"",
		"",
		"",
		"",
		"../images/map1.png",
		"../images/map2.png",
		"../images/map3.png",
		"../images/map4.png",
	};

	const std::vector<sf::Color>inforOfColor = {
		sf::Color(168, 94, 50),
		sf::Color(168, 62, 50),
		sf::Color(168, 68, 50),
		sf::Color(168, 89, 50),
		sf::Color(97, 168, 50),
		sf::Color(80, 168, 50),
		sf::Color(50, 168, 70),
		sf::Color(168, 144, 50),
		sf::Color(50, 168, 60),
		sf::Color(50, 168, 78),
		sf::Color(50,168, 115),
		sf::Color(105,102, 102),
		sf::Color(145,91,15),
		sf::Color(36,77,3),
		sf::Color(0,0,0),
		sf::Color(0,0,0),
		sf::Color(0,0,0),
		sf::Color(0,0,0),
		sf::Color(235, 52, 52),
		sf::Color(0,0,0),
		sf::Color(0,0,0),
		sf::Color(0,0,0),
		sf::Color(0,0,0),
		sf::Color(0,0,0),
		sf::Color(0,0,0),
		sf::Color(0,0,0),
		sf::Color(0,0,0),
	};

	const float speed = 1.f;
	const float gravity = 1.f;

	static AssetManager* instance;

public:
	static AssetManager* getInstance();
	AssetManager();
	~AssetManager();
	
	std::string getImageFile(sf::Color color);
	sf::Vector2f getSize(sf::Color color);
	std::string getMapFile(ID id);
	ID getID(sf::Color color);
	float getSpeed();
	float getGravity();
};


