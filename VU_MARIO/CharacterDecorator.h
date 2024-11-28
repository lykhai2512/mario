#pragma once
#include "PlayableCharacter.h"

class CharacterDecorator : public PlayableCharacter{
protected:
	PlayableCharacter* character;
public:
	void move();
	void hit(NonPlayableCharacter* character);
	void standOn(NonPlayableCharacter* character);
	void beingStoodOn();
	void collect(Item* item);
	void shoot();

	explicit CharacterDecorator(PlayableCharacter* character);
};

