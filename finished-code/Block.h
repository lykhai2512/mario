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
	sf::RectangleShape blocc;
	float sizeX, sizeY;
public:
	Block(sf::Texture& a, float sizeX, float sizeY);
	void move(float dt);
	void jump();
	void die();
	void collect(WorldObject* object);
	void standOn(WorldObject* object);
	void setPositionFor(WorldObject* object);
	void hit(WorldObject* object);
	bool isDead();
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f a);
	sf::FloatRect getGlobalBounds();

};

