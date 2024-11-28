#pragma once
#include "Character.h"
#include "Item.h"
#include "NonPlayableCharacter.h"

class PlayableCharacter : public Character{

public:
	static PlayableCharacter* createCharacter(PlayableCharacterType type,sf::Vector2f position);
	void collect(Item* item);
	void hit(NonPlayableCharacter* character);
	void standOn(NonPlayableCharacter* character);
	void beingStoodOn();
	void shoot();
	void hit(Block* block);
	bool findMinForView(float& minX);

	void setCenterForView(sf::View* view);
	void move();
	void update();
	void reset();
};

