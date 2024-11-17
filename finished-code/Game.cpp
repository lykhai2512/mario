#include "Game.h"

void Game::loadMap(){
	AssetManager* asset_manager = AssetManager::getInstance();

	
}

void Game::draw(sf::RenderWindow* window){
	for (WorldObject* object : this->all_objects) {
		object->draw(window);
	}
}

void Game::start(sf::RenderWindow* window){
	this->loadMap();
	//this->load...
	//this->load...
	this->draw(window);
}

Game::~Game(){
	for (WorldObject* obj : all_objects) {
		delete obj;
	}
}
