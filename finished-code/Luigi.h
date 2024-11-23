#pragma once
#include "PlayableCharacter.h"

class Luigi : public PlayableCharacter{
private:
	const float X_ACCEL = 3, X_MAX = 15;
	const float X_DECEL = 2.5;
	const float Y_INST_SPEED = 40;
public:
	Luigi(sf::Texture* texture, sf::Vector2f size, sf::Vector2f startingPos);
	void hit(NonPlayableCharacter* character) override;
	//void beingStoodOn();
	void collect(Item* item) override;
	void standOn(NonPlayableCharacter* character) override;
	void shoot() override;
	// move/jump inherits playableChar.h
};

