#include "AssetManager.h"

AssetManager* AssetManager::instance = nullptr;


AssetManager* AssetManager::getInstance() {
    if (!instance) {
        instance = new AssetManager;
    }
    return instance;
}

AssetManager::AssetManager(){}


AssetManager::~AssetManager(){
    delete instance;
    instance = nullptr;
}

std::string AssetManager::getImageFile(sf::Color color){
    int id = (int)(getID(color));

    if (id > file.size()) {
        std::cout << "No image for this ID!";
        exit(1);
    }
    return file[id];
}

sf::Vector2f AssetManager::getSize(sf::Color color)
{
    int id = (int)getID(color);

    if (id > size.size()) {
        std::cout << "No size for ID " + std::to_string(id);
        exit(1);
    }
    return size[id];
}

std::string AssetManager::getMapFile(ID id)
{
    return file[(int)id];
}

ID AssetManager::getID(sf::Color color) {
    for (int i = 0; i < inforOfColor.size(); i++) {
        if (inforOfColor[i] == color) {
            return ID(i);
        }
    }
    return ID::none;
}

float AssetManager::getSpeed()
{
    return speed;
}

float AssetManager::getGravity() {
    return gravity;
}

