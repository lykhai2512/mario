#pragma once
#include "WorldObject.h"

enum class CharacterType {
    Mario = 1,
    Luigi = 2
};

class Character : public WorldObject {
private:
    
public:
	static Character* createCharacter(CharacterType type);
    void move();
    void jump();
    void die();
<<<<<<< HEAD
    void collect(WorldObject* object);
    void standOn(WorldObject* object);
    void setPositionFor(WorldObject* object);
    void hit(WorldObject* object);
=======
>>>>>>> b5f28a4db16f4dac39d4209019788812670ed3b0
};

