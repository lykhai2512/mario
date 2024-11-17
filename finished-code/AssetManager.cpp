#include "AssetManager.h"

AssetManager* AssetManager::instance = nullptr;


void AssetManager::readAnimationFile(){

}

void AssetManager::readPositionOfMap(){
    for(int i = 1; i <= numOfMaps; i++){
        std::ifstream read_file(this->positionFile + std::to_string(i) + ".txt");
        
        if(!read_file){
            exit(1);
        }

        std::string type;
        int numOfBlocks;
        while(!read_file.eof()){
            read_file >> type >> numOfBlocks;
            read_file.ignore();

            for(int j = 0; j < types[i].size(); i++){
                if(type == types[j]){
                    for(int k = 0; k < numOfBlocks; k++){
                        sf::Vector2f temp;
                        read_file >> temp.x >> temp.y;
                        this->map[i][j].push_back(temp);
                        read_file.ignore();
                    }
                    break;
                }
            }
        }
        read_file.close();
    }
}

void AssetManager::load(){
    this->readPositionOfMap();
    this->readAnimationFile();
}

std::string AssetManager::getImage(MapType m_type, EntityType e_type, BlockType b_type, ItemType i_type, CharacterType c_type)
{
    int type_of_object = 0;
    if(e_type == EntityType::Block)
        type_of_object = (int)b_type;
    if(e_type == EntityType::Item)
        type_of_object = (int)i_type;
    if(e_type == EntityType::Character)
        type_of_object = (int)c_type;

    return this->baseLink + std::to_string((int)m_type) + "/Blocks/" + this->types[type_of_object] + ".png"; 
}

std::vector<std::vector<sf::Vector2f>> AssetManager::getPosition(MapType m_type){
    return this->map[(int)m_type];
}

std::vector<sf::Vector2f> AssetManager::getPosition(MapType m_type, EntityType e_type, BlockType b_type, ItemType i_type, CharacterType c_type){
    if(e_type == EntityType::Block)
        return this->map[(int)m_type][(int)b_type];
    else if(e_type == EntityType::Item)
        return this->map[(int)m_type][(int)i_type];
    
    return this->map[(int)m_type][(int)c_type];
}

AssetManager* AssetManager::getInstance(){
    if (!instance) {
        instance = new AssetManager;
        instance->load();
    }
    return instance;
}

AssetManager::AssetManager(){
    this->map = std::vector<std::vector<std::vector<sf::Vector2f>>>(numOfMaps,std::vector<std::vector<sf::Vector2f>>(types.size()));
}

AssetManager::~AssetManager(){
    delete instance;
    instance = nullptr;
}
