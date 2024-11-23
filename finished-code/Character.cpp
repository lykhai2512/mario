#include "Character.h"
#include "Mario.h"
#include "Luigi.h"
#include <limits>


Character::Character(){}

Character::~Character(){ 
	delete this->sprite;
	delete this->animation;
	delete this->texture;
	delete this->animation_texture;
	delete this->shape;
}


void Character::move(float dT){ // override
}

void Character::jump(float dT){}

void Character::die(){
	this->alive = false;
}



void Character::standOn(Block* block){ // this likely doesnt need to be overriden
	//write here
	block->beingStoodOn();
}

void Character::beingStoodOn(){ // wait wha

}



void Character::reset(){ // no override
	this->baseGround = std::numeric_limits<float>::max();
}

bool Character::isDead() // yea that makes sense
{
	return !(this->alive);
}

void Character::update(){ // no override? i think
	//check texture;
	this->position.y = this->baseGround;
	this->sprite->setPosition(this->position);
	if (!hasDoneSth) this->sprite->setTexture(*(this->texture)); // is this an idling state?
	else this->sprite->setTexture(*(this->animation_texture));
	this->shape->setPosition(this->position);
}

void Character::draw(sf::RenderWindow& window){ // this should be universal
	this->update();
	window.draw(*sprite);
	window.draw(*shape);
}

