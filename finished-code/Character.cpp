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


void Character::move(){}

void Character::jump(){}

void Character::die(){
	this->alive = false;
}



void Character::standOn(Block* block){
	//write here
	
}

void Character::beingStoodOn(){

}



void Character::reset(){
	this->baseGround = std::numeric_limits<float>::max();
}

bool Character::isDead()
{
	return !(this->alive);
}

void Character::update(){
	//check texture;
	this->position.y = this->baseGround;
	this->sprite->setPosition(this->position);
	if (!hasDoneSth) this->sprite->setTexture(*(this->texture));
	else this->sprite->setTexture(*(this->animation_texture));
	this->shape->setPosition(this->position);
}

void Character::draw(sf::RenderWindow* window){
	this->update();
	window->draw(*sprite);
	window->draw(*shape);
}

