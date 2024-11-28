#include "Mario.h"

Mario::Mario(sf::Texture *texture, sf::Vector2f size, sf::Vector2f startingPos)
{
	this->xAccel = X_ACCEL;
	this->xMax = X_MAX;
	this->yInstSpeed = Y_INST_SPEED;
	this->xDecel = X_DECEL;
	this->state = PositionalState::GROUNDED;
	this->Vx = 0;
	this->Vy = 0;
	
	// this will need further texture loading later
	
	this->shape->setSize(size);
	this->shape->setPosition(startingPos);
	this->sprite->setTextureRect(sf::IntRect(0, 0, size.x, size.y)); // sets the default texture to the first one
}

void Mario::hit(NonPlayableCharacter* character) {
	character->die(); // i guess?
}

//void Mario::beingStoodOn(){
//	this->die(); // i also guess?
//}

void Mario::collect(Item *item)
{
	// pending implementation
}

void Mario::move(){

}


void Mario::shoot()
{
	// pending implementation
}
