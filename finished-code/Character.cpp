
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

void Character::shoot(){}

void Character::becomeSmaller(){}

void Character::die(){}