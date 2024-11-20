#pragma once
#include "WorldObject.h"

enum class CharacterType {
    Mario = 1,
    Luigi = 2
};

enum class EnemyType{
    Goomba = 1,
    Koopa = 2
};

class Character : public WorldObject {
private:
    
public:
	static Character* createCharacter(CharacterType type);
	void move();
	void jump();
	void die();
	void collect(WorldObject* object);
	void standOn(WorldObject* object);
	void setPositionFor(WorldObject* object);
	void hit(WorldObject* object);
};

class Enemy : public Character {
private:

public:
	static Enemy* createEnemy(EnemyType type);
	void move();
        void die();
        void standOn(WorldObject* object);
        void setPositionFor(WorldObject* object);
	void hit(WorldObject* object);
	void chase(WorldObject* object);
};
