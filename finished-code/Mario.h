#pragma once
#include "Character.h"
#include "Map.h"
#include <SFML/Graphics.hpp>
class Mario : public Character
{
private:
	sf::Texture textureSource;
	sf::Sprite sprite;

	float Vx, Vy; // speeds on 2 axis;
	float XAccel, YAccel;
	float XDecel;
	float XCap;

	bool isMidAid;
	bool isAlive;
	//std::vector<WorldObject> inventory;
	int sizeX, sizeY;

public:
	Mario(sf::Texture &tS, float XA, float maxXA, float YA, float XD, int sizeX, int sizeY);
	void move(float dT);
	void jump();
	void die();
	void collect(WorldObject* object);
	void standOn(WorldObject* object);
	void setPositionFor(WorldObject* object);
	void hit(WorldObject* object);
	bool isDead();
	void draw(sf::RenderWindow &window);

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f a);

	// here COMES THE FUN PART

	void mapCollisionHandler(Map &topo);
};

