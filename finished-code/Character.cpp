
#include "Character.h"

Character* Character::createCharacter(CharacterType type)
{
	switch (type) {
	case CharacterType::Mario:
		//return new Mario
		break;

	case CharacterType::Luigi:
		//return new Luigi
		break;
	}
}

void Character::move(){}

void Character::jump(){}

void Character::die(){}

void Character::collect(WorldObject *object){}

void Character::standOn(WorldObject *object){}

void Character::setPositionFor(WorldObject *object){}

void Character::hit(WorldObject *object){}