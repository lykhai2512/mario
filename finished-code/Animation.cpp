#include "Animation.h"



void Animation::handleMarioAnimation(AnimationType a_type)
{
	//jump,die,hurt
}

void Animation::handleLuigiAnimation(AnimationType a_type)
{
}

void Animation::handleCharacterAnimation(CharacterType type, AnimationType a_type)
{
	switch (type) {
		case CharacterType::Mario:
			this->handleMarioAnimation(a_type);
			break;
		case CharacterType::Luigi:
			this->handleLuigiAnimation(a_type);
			break;
		//more for enemy
	}
}

void Animation::handleAll(std::vector<WorldObject*> allObjects){
	
}


