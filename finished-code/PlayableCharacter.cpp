#include "PlayableCharacter.h"
#include "Mario.h"
#include "Luigi.h"

PlayableCharacter* PlayableCharacter::createCharacter(ID type, const std::string& image_file, sf::Vector2f position, sf::Vector2f size, std::vector<AnimationStrategy*> animationStrategy)
{
	PlayableCharacter* result = nullptr;

	switch (type)
	{
	case ID::MARIO:
		//result = new Mario;// pass in the file, call the asset manager to get the texture needed
		break;
	case ID::LUIGI:
		//result = new Luigi;// pass in the file, call the asset manager to get the texture needed
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

//void PlayableCharacter::beingStoodOn(){}

void PlayableCharacter::shoot(){}

void PlayableCharacter::move(float dT) {
	switch (this->state)
	{

	case PositionalState::GROUNDED:
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			Vx -= (Vx >= -xMax) ? 0 : xAccel * dT;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			Vx += (Vx >= xMax) ? 0 : xAccel * dT;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			this->jump(dT);
	}
	break;

	case PositionalState::MID_AIR:
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			Vx -= (Vx >= -xMax) ? 0 : xAccel * dT * 0.5;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			Vx += (Vx >= xMax) ? 0 : xAccel * dT * 0.5;
	}
	break;

	this->shape->move(Vx * dT, Vy * dT);
	this->sprite->move(Vx * dT, Vy * dT);

	decelerator(Vx, xDecel * dT);
	Vy += 3 * dT; // this should be replaced with gravitational acceleration constant. gravity must always be present.

	}
}


void PlayableCharacter::jump(float dt)
{
	Vy -= yInstSpeed;
	this->state = PositionalState::MID_AIR;
}

void PlayableCharacter::decelerator(float& Vx, float VxDecel)
{
	if (Vx > 0)
	{
		Vx -= VxDecel;
		Vx = (Vx < 0) ? 0 : Vx;
	}
	else if(Vx < 0)
	{
		Vx += VxDecel;
		Vx = (Vx > 0) ? 0 : Vx;
	}
}