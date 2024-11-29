#include "Character.h"
#include "Mario.h"
#include "Luigi.h"
#include <limits>


void Character::initVariables(sf::Vector2f position, std::vector<AnimationStrategy*> animationStrategy, std::pair<sf::Texture*, std::vector<sf::IntRect>> images){
	this->position = position;
	this->sprite = new sf::Sprite;
	this->shape = new sf::RectangleShape;
	this->sprite->setTexture(*images.first);
	this->sprite->setTextureRect(images.second[0]);
	
	
	sf::FloatRect floatRect = AssetManager::getInstance()->ToFloatRect(images.second[0]);

	this->shape->setSize(sf::Vector2f(floatRect.getSize().x,floatRect.getSize().y));
	
	animation = new Animation(animationStrategy);
}

Character::Character(){}

Character::~Character(){
	delete this->sprite;
	delete this->animation;
	delete this->shape;
}

void Character::move(){
	
}

void Character::jump(){}

void Character::die(){
	//animation
	this->alive = false;
}

void Character::standOnBlock(Block* block) {
	//write here
	block->beingStoodOn(this->baseGround, this->shape->getGlobalBounds());
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

	if (this->position.y < this->baseGround - this->shape->getSize().y) {
		this->position.y += 5;
		this->isMidAir = true;
	}
	else{ // this sets position y for base ground, aka when it touches the ground
		this->isMidAir = false;
		this->position.y = this->baseGround - this->shape->getSize().y;
		Vy = 0;
	}

	this->sprite->setPosition(this->position);
	this->shape->setPosition(this->position);
	Vy += (Vy >= 0)? 0 : 0.5;
}

void Character::draw(sf::RenderWindow* window){
	window->draw(*sprite);
}

