#pragma once
#include "Character.h"
#include "Item.h"
#include "NonPlayableCharacter.h"

class PlayableCharacter : public Character{
public:
	static PlayableCharacter* createCharacter(ID type, const std::string& image_file, sf::Vector2f position, sf::Vector2f size,std::vector<AnimationStrategy*> animationStrategy);
	virtual void collect(Item* item);
	virtual void hit(NonPlayableCharacter* character);
	virtual void standOn(NonPlayableCharacter* character);
	void beingStoodOn();
	virtual void shoot();
	void move();
};

