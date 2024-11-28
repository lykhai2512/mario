//need adjustment

#include "NonPlayableCharacter.h"
#include "Goomba.h"
#include "KoopaTroopa.h"
#include "AutomaticStrategy.h"
#include "LimitedTimeStrategy.h"


NonPlayableCharacter* NonPlayableCharacter::createCharacter(NonPlayableCharacterType type, sf::Vector2f position)
{

	NonPlayableCharacter* result = nullptr;

	switch (type)
	{
	case NonPlayableCharacterType::goomba:
		result = new Goomba;
		break;
	case NonPlayableCharacterType::koopatroopa:
		result = new KoopaTroopa;
		break;
	//case
	//case
	default:
		result = nullptr;
		break;
	}

	
	if (result)
	{
		std::pair<sf::Texture*, std::vector<sf::IntRect>> images = AssetManager::getInstance()->getNonPlayableCharacter(type);
		
		result->initVariables(position, {new AutomaticStrategy(images.first,images.second,1.0 / 60)}, images);
	}

	return result;
}

void NonPlayableCharacter::move(){
	this->position.x += this->speed;
}

void NonPlayableCharacter::standOn(Character* character){
	character->beingStoodOn();
}

void NonPlayableCharacter::hit(NonPlayableCharacter* character){
	character->beingHitByNonPlayable(this->shape->getGlobalBounds(), this->speed);
}

void NonPlayableCharacter::hit(Block* block){
	block->beingHitByNonPlayable(this->shape->getGlobalBounds(), this->speed);
}

void NonPlayableCharacter::beingHitByNonPlayable(const sf::FloatRect& bounds, float& o_speed){
	sf::FloatRect m_bounds = this->shape->getGlobalBounds();

	if (bounds.intersects(m_bounds)) {
		o_speed *= -1;
		this->speed *= -1;
		
		this->move();
	}
}

void NonPlayableCharacter::update(){
	this->move();

	Character::update();
}

void NonPlayableCharacter::beingStoodOn(const sf::FloatRect& bounds){
	sf::FloatRect m_bounds = this->shape->getGlobalBounds();

	
	bool horizontalOverlap = bounds.left + bounds.width > m_bounds.left && bounds.left < m_bounds.left + m_bounds.width;

	bool verticalOverlap = bounds.top + bounds.height >= m_bounds.top && bounds.top + bounds.height <= m_bounds.top + 5.f;

	if (horizontalOverlap && verticalOverlap) {
		this->die();
	}
}

void NonPlayableCharacter::beingHit(const sf::FloatRect& bounds, bool& alive){
	sf::FloatRect m_bounds = this->shape->getGlobalBounds();

	if (this->alive && bounds.intersects(m_bounds)) {
		alive = false; 
	}
}
