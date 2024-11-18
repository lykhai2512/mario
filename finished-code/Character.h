#pragma once
#include "WorldObject.h"
#include "AssetManager.h"

enum class CharacterType {
    Mario = 1,
    Luigi = 2
};

class Character : public WorldObject {
private:

public:
	//static Character* createCharacter(CharacterType type);
	virtual void move(float dT) = 0;
	virtual void jump() = 0;//this is bundled in with move();
	virtual void die() = 0;
	virtual void collect(WorldObject* object) = 0; //sthis is probably not necessary, should be handled where we handle collision
	virtual void standOn(WorldObject* object) = 0;
	virtual void setPositionFor(WorldObject* object) = 0;
	virtual void hit(WorldObject* object) = 0;
	virtual bool isDead() = 0;
	virtual void draw(sf::RenderWindow &window) = 0;
};

