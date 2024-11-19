#pragma once
#include "Character.h"

class Mario : public Character{
public:
	Mario();
	void move();
	void hit(WorldObject* object);
};

