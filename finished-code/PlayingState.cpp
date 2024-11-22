#include "PlayingState.h"
#include "Block.h"
#include "Item.h"
#include "KeyPressStrategy.h"
#include "LimitedTimeStrategy.h"
#include "AutomaticStrategy.h"
#include "Character.h"

void PlayingState::createMap(){
	AssetManager* instance = AssetManager::getInstance();
	std::string mapFile = instance->getMapFile(mapType);

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
			int id = (int)instance->getID(pixel);
			if (id >= 0 && id <= 13) {
				all_blocks.push_back(Block::createBlock(instance->getID(pixel), instance->getImageFile(pixel), sf::Vector2f(i * 50.f,j * 50.f), instance->getSize(pixel)));
			}
			else if (id >= 14 && id <= 17) {
				all_items.push_back(Item::createItem(instance->getID(pixel), instance->getImageFile(pixel), sf::Vector2f(i * 50.f, j * 50.f), instance->getSize(pixel)));
			}

			else if (id >= 18 && id <= 19) {
				all_good_characters.push_back(PlayableCharacter::createCharacter(instance->getID(pixel), instance->getImageFile(pixel), sf::Vector2f(i * 50.f, j * 50.f), instance->getSize(pixel),{new AutomaticStrategy,new KeyPressStrategy,new LimitedTimeStrategy}));
			}

			//another if for bad character

		}

		//if win all levels-->state = menustate
	}
	//read from map file, get Id from color and create approriate objects
}

void PlayingState::update(sf::RenderWindow* window){
	//4 for loops to update all obj
	collision.handleAllCollision(this->all_good_characters,this->all_bad_characters,this->all_items,this->all_blocks);
}

void PlayingState::drawMap(sf::RenderWindow* window){
	
	for (Block* block : this->all_blocks) {
		block->draw(window);
	}

	for (Item* item : this->all_items) {
		item->draw(window);
	}

	for (NonPlayableCharacter* bad_character : this->all_bad_characters) {
		bad_character->draw(window);
	}

	for (PlayableCharacter* good_character : this->all_good_characters) {
		good_character->draw(window);
	}
}

void PlayingState::execute(sf::RenderWindow* window){
	if (!this->isMapCreated) {
		this->createMap();
		this->isMapCreated = true;
	}
	else {
		collision.handleAllCollision(all_good_characters, all_bad_characters, all_items, all_blocks);
		this->update(window);
		this->drawMap(window);
	}
}
