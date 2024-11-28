#pragma once
#include "Character.h"

class NonPlayableCharacter : public Character{
private:
	float speed = 0.5f;

public:
	static NonPlayableCharacter* createCharacter(NonPlayableCharacterType type, sf::Vector2f position);
	void move();
	void standOn(Character* character);
	void hit(NonPlayableCharacter* character);
	void hit(Block* block);
	void beingHitByNonPlayable(const sf::FloatRect& bounds, float& speed);
	void update();

	void beingStoodOn(const sf::FloatRect& bounds);
	void beingHit(const sf::FloatRect& bounds,bool &alive);
};

