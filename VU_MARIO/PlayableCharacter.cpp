#include "PlayableCharacter.h"
#include "Mario.h"
#include "Luigi.h"
#include "KeyPressStrategy.h"
#include "AutomaticStrategy.h"
#include "LimitedTimeStrategy.h"


void tickDownToZero(float& speed, float amount)
{
	if (speed > 0)
	{
		speed -= amount;
		speed = (speed < 0) ? 0 : speed;
	}
	else if(speed < 0)
	{
		speed += amount;
		speed = (speed > 0) ? 0 : speed;
	}
}
// debug
#include <iostream>

PlayableCharacter* PlayableCharacter::createCharacter(PlayableCharacterType type, sf::Vector2f position)
{
	PlayableCharacter* result = nullptr;
	AssetManager* instance = AssetManager::getInstance();

	int character = (int)type;

	if ((character >= 1 && character <= 4) || (character >= 6 && character % 2 == 0)) {
		result = new Mario;
	}

	else {
		result = new Luigi;
	}

	if (result)
	{
		std::pair<sf::Texture*, std::vector<sf::IntRect>> images = instance->getPlayableCharacter(type);

		result->initVariables(position,{new KeyPressStrategy(images.first,images.second,1.0 / 60),new LimitedTimeStrategy(images.first,images.second,1.0 / 60),new AutomaticStrategy(images.first,images.second,1.0 / 60)},images);
	}

	return result;
}

void PlayableCharacter::collect(Item * item){
	item->beingCollected(this->shape->getGlobalBounds());
}

void PlayableCharacter::hit(NonPlayableCharacter* character){
	character->beingHit(this->shape->getGlobalBounds(),this->alive); 
}

void PlayableCharacter::standOn(NonPlayableCharacter* character){
	character->beingStoodOn(this->shape->getGlobalBounds());
}

void PlayableCharacter::beingStoodOn(){

}

void PlayableCharacter::shoot(){

}

void PlayableCharacter::hit(Block* block){
	block->beingHit(this->shape->getGlobalBounds(),this->position);
}

bool PlayableCharacter::findMinForView(float& minX){
	if (position.x < minX) {
		minX = position.x;
		return true;
	}

	return false;
}

void PlayableCharacter::setCenterForView(sf::View* view){
	if (view->getCenter().x < this->position.x) {
		view->setCenter(this->position.x,view->getCenter().y);
	}
}

void PlayableCharacter::move(){

	std::cout << Vx << "\t" << Vy << "\n";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !isMidAir) {
		std::cout << "jump press\n";
		Vy = -16.5;
		isMidAir = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		Vx += 2;
		Vx = (Vx > 5) ? 5 : Vx;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		Vx -= 2;
		Vx = (Vx < -5) ? -5 : Vx;

	}	
	position.x += Vx;
	position.y += (Vy < 0)? Vy : 0;

	tickDownToZero(Vx, 0.5);

}

void PlayableCharacter::update(){
	this->move();

	Character::update(); // update will have gravity applied
}

void PlayableCharacter::reset(){
	Character::reset();
}


// custom overriding for standOnBlock