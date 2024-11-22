#include "Animation.h"

Animation::Animation(){}

Animation::Animation(std::vector<AnimationStrategy*> animation_strategies){
	this->strategies = animation_strategies;
}

Animation::Animation(Animation& other){
	for (int i = 0; i < other.strategies.size(); i++) {
		AnimationStrategy* newStrategy = new AnimationStrategy;
		*newStrategy = *other.strategies[i];
		this->strategies.push_back(newStrategy);
	}
}

Animation::~Animation(){
	for (AnimationStrategy* strategy : this->strategies) {
		delete strategy;
	}
}

void Animation::addStrategy(AnimationStrategy* animationStrategy){
	this->strategies.push_back(animationStrategy);
}
