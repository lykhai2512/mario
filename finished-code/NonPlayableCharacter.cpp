//need adjustment

#include "NonPlayableCharacter.h"
#include "Goomba.h"
#include "KoopaTroopa.h"

NonPlayableCharacter* NonPlayableCharacter::createCharacter(ID type, const std::string& image_file, sf::Vector2f position, sf::Vector2f size, std::vector<AnimationStrategy*> animationStrategy)
{
	NonPlayableCharacter* result = nullptr;

	switch (type)
	{
	case ID::Mario:
		result = new Goomba;
		break;
	case ID::Luigi:
		result = new KoopaTroopa;
		break;
	default:
		result = nullptr;
		break;
	}

	if (result)
	{
		result->texture = new sf::Texture;
		if (!result->texture->loadFromFile(image_file)) exit(1);

		result->sprite->setTexture(*(result->texture));
		result->shape->setSize(size);
		result->position = position;
		result->baseGround = result->position.y + result->shape->getSize().y;
		result->animation = new Animation(animationStrategy);
	}

	return result;
}

void NonPlayableCharacter::move(){
}

void NonPlayableCharacter::standOn(Character* character){
	
}

void NonPlayableCharacter::hit(NonPlayableCharacter* character)
{
}

void NonPlayableCharacter::beingStoodOn(){
}
