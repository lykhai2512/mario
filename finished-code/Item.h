#pragma once
#include "WorldObject.h"

enum class ItemType {
	GoodMushroom = 1,
	Flower = 2,
	Coin = 3,
	Star = 4
};


class Item : public WorldObject{
private:

public:
	static Item* createItem(ItemType type);
	
	void move();
    void jump();
    void die();
    void collect(WorldObject* object);
    void standOn(WorldObject* object);
    void setPositionFor(WorldObject* object);
    void hit(WorldObject* object);
};

