#include "PlayableCharacter.h"
#include "Mario.h"
#include "Luigi.h"
#include "KeyPressStrategy.h"
#include "AutomaticStrategy.h"
#include "LimitedTimeStrategy.h"

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
	block->beingHit(this->shape->getGlobalBounds(),this->baseRoof,this->position);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		position.y -= 10.f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		position.x += 5.f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		position.x -= 5.f;
	}
}

void PlayableCharacter::update(){
	this->move();

	if (position.y < baseRoof + this->shape->getSize().y) {
		position.y = baseRoof + this->shape->getSize().y;
	}

	Character::update();
}

void PlayableCharacter::reset(){
	Character::reset();
	baseRoof = std::numeric_limits<float>::min();
}


