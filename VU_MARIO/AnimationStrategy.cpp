#include "AnimationStrategy.h"


AnimationStrategy::AnimationStrategy(){
	texture = nullptr;
	curFrameNum = 0;
}

AnimationStrategy::AnimationStrategy(sf::Texture* texture, std::vector<sf::IntRect> frames, const float& SPF) : texture(texture), frames(frames),frameSize(frames.size()),SPF(SPF),curFrameNum(0){}

AnimationStrategy::AnimationStrategy(AnimationStrategy& other) : texture(texture),frames(frames),frameSize(frames.size()),SPF(SPF), curFrameNum(0) {}

AnimationStrategy::~AnimationStrategy(){}

void AnimationStrategy::die(const float& deltaTime, sf::Sprite* sprite){}

void AnimationStrategy::moveleft(const float& deltaTime, sf::Sprite* sprite){}

void AnimationStrategy::moveright(const float& deltaTime, sf::Sprite* sprite){}

void AnimationStrategy::changeAutomatically(const float& deltaTime, sf::Sprite* sprite){}

