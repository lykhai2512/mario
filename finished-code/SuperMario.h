#pragma once
#include "CharacterDecorator.h"

class SuperMario : public CharacterDecorator{

public:
	void hit(NonPlayableCharacter* character);	
	void move();
	void beingStoodOn();
};


