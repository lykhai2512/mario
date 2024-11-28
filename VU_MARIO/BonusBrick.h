#pragma once
#include "Block.h"

class BonusBrick : public Block{
private:
	Animation* animation;
public:
	BonusBrick();
	BonusBrick(std::vector<AnimationStrategy*> strategy);
	~BonusBrick();


};