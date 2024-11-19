#include "Character.h"
#include "Mario.h"
#include "Luigi.h"


Character::Character(){}

Character::~Character(){
	delete this->texture;
}

Character* Character::createCharacter(ID type, const std::string& image_file, sf::Vector2f position, sf::Vector2f size, float baseGround)
{
	Character* result = nullptr;
	
	switch (type)
	{
	case ID::Mario:
		result = new Mario;
		break;
	case ID::Luigi:
		result = new Luigi;
		break;
	default:
		result = nullptr;
		break;
	}

	if (result)
	{
		result->texture = new sf::Texture;
		if (!result->texture->loadFromFile(image_file)) exit(1);

		result->shape.setSize(size);
		result->shape.setTexture(result->texture);
		result->position = position;
		result->baseGround = baseGround;
	}
	
	return result;
}

void Character::move(){}

void Character::jump(){

}

void Character::die()
{
}

void Character::collect(WorldObject* item)
{
}

void Character::beingCollected(sf::Vector2f& position, sf::Texture*& texture, sf::FloatRect& bounds, float& baseGround)
{
}

void Character::standOn(WorldObject* block)
{
}

void Character::beingStoodOn(sf::Vector2f& position, sf::Texture* texture, sf::FloatRect& bounds, float& baseGround)
{
}

void Character::hit(WorldObject* object)
{
}

void Character::beingHit(sf::Vector2f& position, sf::Texture* texture, sf::FloatRect& bounds, float& baseGround)
{
}



bool Character::isDead()
{
	return false;
}

void Character::update(){
	

}

void Character::draw(sf::RenderWindow* window){
	
}






