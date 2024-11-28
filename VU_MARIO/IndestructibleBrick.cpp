#include "IndestructibleBrick.h"

IndestructibleBrick::IndestructibleBrick(){}

void IndestructibleBrick::beingHit(const sf::FloatRect& bounds, sf::Vector2f& position){
	sf::FloatRect m_bounds = this->shape->getGlobalBounds();

	Block::beingHit(bounds, position);

	if (m_bounds.intersects(bounds) && bounds.top >= m_bounds.top + 10.f) {
		this->position.y -= 10.f;
	}
}
