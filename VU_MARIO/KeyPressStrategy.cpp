#include "KeyPressStrategy.h"

KeyPressStrategy::KeyPressStrategy() : AnimationStrategy(){}

KeyPressStrategy::KeyPressStrategy(sf::Texture* texture, std::vector<sf::IntRect> frames, const float& SPF) : AnimationStrategy(texture,frames,SPF){}

KeyPressStrategy::KeyPressStrategy(const KeyPressStrategy& other) : AnimationStrategy(other.texture,other.frames,other.SPF){}


void KeyPressStrategy::moveleft(const float& deltaTime, sf::Sprite* sprite){
	if (deltaTime > SPF) {
		if (curFrameNum < frameSize - 3) {
			curFrameNum++;
		}
		else curFrameNum = 0;
	}
	sprite->setTexture(*this->texture);
	sprite->setTextureRect(this->frames[curFrameNum]);
	sprite->setScale(-1.f, 1.f);
}

void KeyPressStrategy::moveright(const float& deltaTime, sf::Sprite* sprite){
	if (deltaTime > SPF) {
		if (curFrameNum < frameSize - 3) {
			curFrameNum++;
		}
		else curFrameNum = 0;
	}
	sprite->setTexture(*this->texture);
	sprite->setTextureRect(this->frames[curFrameNum]);
}

void KeyPressStrategy::jump(const float& deltaTime, sf::Sprite* sprite){
	if (deltaTime > SPF) {
		curFrameNum = frameSize - 2;
	}
	sprite->setTexture(*this->texture);
	sprite->setTextureRect(this->frames[curFrameNum]);
}

KeyPressStrategy::~KeyPressStrategy(){}


