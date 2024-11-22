#pragma once
#include "Character.h"

class NonPlayableCharacter : public Character{
public:
	static NonPlayableCharacter* createCharacter(ID type, const std::string& image_file, sf::Vector2f position, sf::Vector2f size, std::vector<AnimationStrategy*> animationStrategy);
	void move();
	void standOn(Character* character);
	void hit(NonPlayableCharacter* character);
	void beingStoodOn();
};

