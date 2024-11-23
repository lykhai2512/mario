#pragma once
#include "Character.h"
#include "Item.h"
#include "NonPlayableCharacter.h"

enum PositionalState {
	MID_AIR,
	GROUNDED
};

enum ID {
	MARIO,
	LUIGI
};

class PlayableCharacter : public Character{
protected:
	float xAccel, xMax;
	float xDecel;
	float yInstSpeed;
	void decelerator(float& Vx, float VxDecel);
	PositionalState state;

public:
	static PlayableCharacter* createCharacter(ID type, const std::string& image_file, sf::Vector2f position, sf::Vector2f size,std::vector<AnimationStrategy*> animationStrategy);
	virtual void collect(Item* item);
	virtual void hit(NonPlayableCharacter* character);
	virtual void standOn(NonPlayableCharacter* character);
	virtual void shoot();


	virtual void move(float dT) override;
	virtual void jump(float dT) override;
	// die inherits from character.h
	// void beingStoodOn(); inherits from character.h
	// void standOn(Block* block); inherits from character.h
	// void reset(); inherits from character.h
	// bool isDead(); inherits from character.h
	// void update(); inherits from character.h
	// draw inherits from character.h

};

