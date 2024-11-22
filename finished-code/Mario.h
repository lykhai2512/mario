#pragma once
#include "PlayableCharacter.h"

class Mario : public PlayableCharacter{
public:
	Mario();
	void hit(NonPlayableCharacter* character);
	void beingStoodOn();
};

