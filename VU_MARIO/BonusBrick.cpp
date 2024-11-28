#include "BonusBrick.h"
#include "AutomaticStrategy.h"

BonusBrick::BonusBrick(){
	animation = nullptr;
}

BonusBrick::BonusBrick(std::vector<AnimationStrategy*> strategy){
	animation = new Animation(strategy);
}

BonusBrick::~BonusBrick(){
	delete animation;
}
