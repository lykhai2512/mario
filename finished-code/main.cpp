#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "WorldObject.h"
#include "Block.h"
#include "Item.h"
#include "Character.h"



int main() {
    
    AssetManager* temp = AssetManager::getInstance();
    std::vector<std::vector<sf::Vector2f>>positions = temp->getPosition(MapType::map1);
    
    std::vector<WorldObject*>all_obj;
    
    for(int i = 0; i < positions.size(); i++){
        for(int j = 0; j < positions[i].size(); j++){
            all_obj.push_back(Block::createBlock((BlockType)j,temp->getImage(MapType::map1,EntityType::Block,(BlockType)j),positions[i][j]));
        }
    }




    sf::RenderWindow* window;
    window = new sf::RenderWindow(sf::VideoMode(1200, 480), "SFML works!");

    sf::View view(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));


    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            view.move(-1.f, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            view.move(1.f, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            view.move(0, -1.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            view.move(0, 1.f);
        }

        window->clear();
        for (WorldObject* object : all_obj) {
            if(object) object->draw(window);
        }
        window->setView(view);
        window->display();
    }

    delete window;
  

    return 0;
}
