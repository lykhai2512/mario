#include "PlayingState.h"

void PlayingState::createMap(){
	AssetManager* instance = AssetManager::getInstance();
	
	//read from map file, get Id from color and create approriate objects
}

void PlayingState::update(sf::RenderWindow* window){
	//4 for loops to update all obj
	//update collision
}

void PlayingState::drawMap(sf::RenderWindow* window){
	//4 for loops to draw all obj
}

void PlayingState::execute(sf::RenderWindow* window){
	if (!this->isMapCreated) {
		this->createMap();
	}
	else {
		this->update(window);
		this->drawMap(window);
	}
}
