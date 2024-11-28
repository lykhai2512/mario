#pragma once
#include "AnimationStrategy.h"


class KeyPressStrategy : public AnimationStrategy{
public:
	KeyPressStrategy();
	KeyPressStrategy(sf::Texture* texture, std::vector<sf::IntRect> frames, const float& SPF);
	KeyPressStrategy(const KeyPressStrategy& other);

	void moveleft(const float& deltaTime, sf::Sprite* sprite);
	void moveright(const float& deltaTime, sf::Sprite* sprite);
	void jump(const float& deltaTime, sf::Sprite* sprite);
	~KeyPressStrategy();
};

