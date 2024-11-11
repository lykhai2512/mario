#pragma once

#include "WorldObject.h"

enum class BlockType {
	none = 0,
	ground = 1,
	brick = 2,
	specialBrick = 3,
	horizontalPipe = 4,
	verticalPipe = 5,
	baseBrick = 6,
	cloud = 7,
	castle = 8,
	flag = 9,
	tree = 10
};

class Block : public WorldObject {
private:
	std::map<int, sf::Vector2f> size = {
	{1,sf::Vector2f(50.f,50.f)},
	{2,sf::Vector2f(50.f,50.f)},
	{3,sf::Vector2f(50.f,50.f)},
	{4,sf::Vector2f(100.f,150.f)},
	{5,sf::Vector2f(100.f,150.f)},
	{6,sf::Vector2f(50.f,50.f)},
	{7,sf::Vector2f(300.f,200.f)},
	{8,sf::Vector2f(300.f,400.f)},
	{9,sf::Vector2f(20.f,500.f)},
	{10,sf::Vector2f(300.f,200.f)},
	};


public:
	static Block* createBlock(BlockType type);
	void move();
    void jump();
    void die();
    void collect(WorldObject* object);
    void standOn(WorldObject* object);
    void setPositionFor(WorldObject* object);
    void hit(WorldObject* object);
};

