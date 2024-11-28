#pragma once
#include "AnimationStrategy.h"

class AutomaticStrategy : public AnimationStrategy{
public:
	AutomaticStrategy();
	AutomaticStrategy(sf::Texture* texture, std::vector<sf::IntRect> frames, const float& SPF);
	AutomaticStrategy(const AutomaticStrategy& other);

	void changeAutomatically(const float& deltaTime, sf::Sprite* sprite);
	~AutomaticStrategy();
};

