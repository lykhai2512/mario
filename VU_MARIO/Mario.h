#pragma once
#include "PlayableCharacter.h"



class Mario : public PlayableCharacter{
<<<<<<< HEAD:VU_MARIO/Mario.h

public:
	Mario();
	void hit(NonPlayableCharacter* character);
	void beingStoodOn();
	void move();
=======
private:
	const float X_ACCEL = 4, X_MAX = 20;
	const float X_DECEL = 3;
	const float Y_INST_SPEED = 30;
public:
	Mario(sf::Texture* texture, sf::Vector2f size, sf::Vector2f startingPos);
	void hit(NonPlayableCharacter* character) override;
	//void beingStoodOn();
	void collect(Item* item) override;
	void standOn(NonPlayableCharacter* character) override;
	void shoot() override;
 
	// move and jump inherits from playableCharacter.h
	// die inherits from character.h
	
	// beingStoodOn inherits from PC.h
	// standOn(block) inherits from PC.h
	// reset inherits from PC.h
	// isDead() // inherits from character.h

	// draw inherits from character.h
>>>>>>> 38eac82cadfc71f71e720716daf4a46ad0c2b960:finished-code/Mario.h
};

