#pragma once
#include "Character.h"
#include "Block.h"
#include "Item.h"
#include "Sound.h"

typedef void(*operation)();

class Collision {
private:

    //for first function in public
    void CharacterInLeftOfBlock(WorldObject* character, WorldObject* block, operation);
    void CharacterInRightOfBlock(WorldObject* character, WorldObject* block, operation);
    void CharacterOnTopOfBlock(WorldObject* character, WorldObject* block, operation);
    void CharacterHitBlockFromBelow(WorldObject* character, WorldObject* block, operation);
    //for second (special case for turtle,...)
    void onTopOfEnemy(WorldObject* character, WorldObject* enemy, operation);
    void onRightOfEnemy(WorldObject* character, WorldObject* enemy, operation);
    void onLeftOfEnemy(WorldObject* character, WorldObject* enemy, operation);
    //for third

    //...

public:
    //strategy design pattern, for last function
    void CharacterAndBlock(WorldObject* character, WorldObject* block, operation);
    void CharacterAndEnemy(WorldObject* character, WorldObject* enemy, operation);
    void EnemyAndBlock(WorldObject* enemy, WorldObject* block, operation);
    //...

    //last function
    void handleAllCollision(std::vector<WorldObject*>world_objects, SoundManager allSounds);
};