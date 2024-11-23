#include "Luigi.h"

Luigi::Luigi(sf::Texture* texture, sf::Vector2f size, sf::Vector2f startingPos)
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
	this->sprite->setTextureRect(sf::IntRect(0, 0, size.x, size.y));
}

void Luigi::hit(NonPlayableCharacter* character)
{
	character->die();
}

//void Luigi::beingStoodOn()
//{
//	this->die();
//}

void Luigi::collect(Item* item)
{
	// pending
}

void Luigi::standOn(NonPlayableCharacter* character)
{
	this->hit(character);
}

void Luigi::shoot()
{
	// 
}