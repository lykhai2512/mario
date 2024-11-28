#pragma once
#include<SFML/Graphics.hpp>
#include "AnimationStrategy.h"

class Animation {
private:
	std::vector<AnimationStrategy*> strategies;
public:
	Animation();
	Animation(std::vector<AnimationStrategy*>animation_strategies);
	Animation(Animation& other);
	~Animation();
	void addStrategy(AnimationStrategy* animationStrategy);
};










