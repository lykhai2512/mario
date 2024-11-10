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
    virtual void shoot();
    virtual void becomeSmaller();
    void die();
    void becomeSmaller();
};

