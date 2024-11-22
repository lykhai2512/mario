#include "PlayableCharacter.h"
#include "Mario.h"
#include "Luigi.h"

PlayableCharacter* PlayableCharacter::createCharacter(ID type, const std::string& image_file, sf::Vector2f position, sf::Vector2f size, std::vector<AnimationStrategy*> animationStrategy)
{
	PlayableCharacter* result = nullptr;

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

		result->sprite->setTexture(*(result->texture));
		result->shape->setSize(size);		
		result->position = position;
		result->baseGround = result->position.y + result->shape->getSize().y;
		result->animation = new Animation(animationStrategy);
	}

	return result;
}

void PlayableCharacter::collect(Item* item){
	
}

void PlayableCharacter::hit(NonPlayableCharacter* character){}

void PlayableCharacter::standOn(NonPlayableCharacter* character){	}

void PlayableCharacter::beingStoodOn(){}

void PlayableCharacter::shoot(){}

void PlayableCharacter::move(){}
