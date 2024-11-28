#include "LimitedTimeStrategy.h"

LimitedTimeStrategy::LimitedTimeStrategy() : AnimationStrategy(){}

LimitedTimeStrategy::LimitedTimeStrategy(sf::Texture* texture, std::vector<sf::IntRect> frames, const float& SPF) : AnimationStrategy(texture,frames,SPF){}

LimitedTimeStrategy::LimitedTimeStrategy(const LimitedTimeStrategy& other) : AnimationStrategy(other.texture,other.frames,other.SPF){}

void LimitedTimeStrategy::die(const float& deltaTime, sf::Sprite* sprite){
	if (deltaTime > SPF) {
		sprite->setTexture(*this->texture);
		sprite->setTextureRect(this->frames[frameSize - 1]);
	}
}

LimitedTimeStrategy::~LimitedTimeStrategy(){}




