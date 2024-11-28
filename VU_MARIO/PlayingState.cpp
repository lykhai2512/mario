#include "PlayingState.h"
#include "Block.h"
#include "Item.h"
#include "KeyPressStrategy.h"
#include "LimitedTimeStrategy.h"
#include "AutomaticStrategy.h"
#include "Character.h"

void PlayingState::createMap(){
	AssetManager* instance = AssetManager::getInstance();
	
	view = new View(sf::FloatRect(0,0,1200.f,600.f));

	std::string mapFile = instance->getMapFile(this->mapNum);

	

	sf::Image readMap;
	if (!readMap.loadFromFile(mapFile)) {
		std::cout << "Cannot read file " + mapFile;
		exit(1);
	}

	unsigned int width = readMap.getSize().x;
	unsigned int height = readMap.getSize().y;
	

	for (unsigned int j = 0; j < height; j++) {
		for (unsigned int i = 0; i < width; i++) {
			sf::Color pixel = readMap.getPixel(i, j);


			int type = 0;
			//call this to get type , id is id in the type
			int id = instance->getID(pixel,type);

			//create blocks, or items, or characters depends on ID
			if (type >= 1 && type <= 16) {
				all_blocks.push_back(Block::createBlock(BlockType(id), sf::Vector2f(i * 32.f, j * 32.f)));
			}

			else if (type >= 17 && type <= 20) {
				std::cout << type << " " << id;
				all_items.push_back(Item::createItem(ItemType(id), sf::Vector2f(i * 32.f, j * 32.f)));
			}

			else if (type >= 21 && type <= 24) {
				all_non_playable_characters.push_back(NonPlayableCharacter::createCharacter(NonPlayableCharacterType(id), sf::Vector2f(i * 32.f, j * 32.f)));
			}

			else if (type >= 25 && type <= 35) {
				all_playable_characters.push_back(PlayableCharacter::createCharacter(PlayableCharacterType(id), sf::Vector2f(i * 32.f, j * 32.f)));
			}
			
		}
	}

}

void PlayingState::update(sf::RenderWindow* window){
	
	
	for (Block* block : all_blocks) {
		block->update();
	}

	for (Item* item : all_items) {
		item->update();
	}

	for (NonPlayableCharacter* non_playable : all_non_playable_characters) {
		non_playable->update();
	}

	for (PlayableCharacter* playable : all_playable_characters) {
		playable->update();
	}
	
	collision.handleAllCollision(this->all_playable_characters,this->all_non_playable_characters,this->all_items,this->all_blocks);
	
	view->update(all_playable_characters, window);
}

void PlayingState::drawMap(sf::RenderWindow* window){
	
	for (Block* block : this->all_blocks) {
		if(!block->isDead())
			block->draw(window);
	}

	for (Item* item : this->all_items) {
		if (!item->isDead())
			item->draw(window);
	}

	for (NonPlayableCharacter* non_playable : this->all_non_playable_characters) {
		if (!non_playable->isDead())
			non_playable->draw(window);
	}

	for (PlayableCharacter* playable : this->all_playable_characters) {
		if (!playable->isDead())
			playable->draw(window);
	}

	view->setForWindow(window);
}

PlayingState::PlayingState(){}

PlayingState::~PlayingState(){
	for (PlayableCharacter* character : all_playable_characters) {
		delete character;
	}

	for (NonPlayableCharacter* character : all_non_playable_characters) {
		delete character;
	}

	for (Block* block : all_blocks) {
		delete block;
	}

	for (Item* item : all_items) {
		delete item;
	}

	delete view;
}

void PlayingState::execute(sf::RenderWindow* window){

	if (this->isMapCreated == false) {
		this->createMap();
		this->isMapCreated = true;
	}
	
	this->update(window);
	
	this->drawMap(window);
}

void PlayingState::addCoin(){
	this->coin++;
}

void PlayingState::addScore(){
	this->score += 100;
}

void PlayingState::decreaseLives(){
	this->lives--;
	if (lives == 0) {
		this->active = false;
	}
}

void PlayingState::changeMap(){
	if (mapNum < 3) {
		mapNum++;
		this->restart();
	}
}

void PlayingState::restart(){
	//delete all, empty array
	this->isMapCreated = false;
}

bool PlayingState::isActive()
{
	return this->active;
}




