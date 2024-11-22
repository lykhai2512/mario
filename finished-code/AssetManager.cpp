#include "AssetManager.h"

AssetManager* AssetManager::instance = nullptr;


void AssetManager::load(){
    this->loadBlocks();
    this->loadItems();
    this->loadNonPlayableCharacters();
    this->loadPlayableCharacters();
}

void AssetManager::loadBlocks(){
    sf::Texture readFile;
    if (!readFile.loadFromFile(FILE[0])) {
        std::cout << "Cannot load from file " + FILE[0];
        exit(1);
    }

    float offsetX = 0;

    for (int i = 0; i < NUMBER_OF_BLOCKS; i++) {
        sf::Sprite* new_sprite = new sf::Sprite;
        new_sprite->setTexture(readFile);
        new_sprite->setTextureRect(sf::IntRect((int)offsetX,0,BlockSize[i].x, BlockSize[i].y));
        blocks.push_back(new_sprite);

        offsetX += BlockSize[i].x;
    }
}




AssetManager* AssetManager::getInstance() {
    if (!instance) {
        instance = new AssetManager;
        instance->load();
    }
    return instance;
}

AssetManager::AssetManager(){}


AssetManager::~AssetManager(){
    delete instance;
    

    instance = nullptr;

}






