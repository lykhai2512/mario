#include "CharacterDecorator.h"

void CharacterDecorator::move(){
	this->character->move();
}

void CharacterDecorator::hit(NonPlayableCharacter* character){
	this->character->hit(character);
}

void CharacterDecorator::standOn(NonPlayableCharacter* character){
	this->character->standOn(character);
}

void CharacterDecorator::beingStoodOn(){
	this->character->beingStoodOn();
}

void CharacterDecorator::collect(Item* item){
	this->character->collect(item);
}

void CharacterDecorator::shoot(){
	this->character->shoot();
}

CharacterDecorator::CharacterDecorator(PlayableCharacter* character) : character(character){}
