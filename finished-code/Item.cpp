#include "Item.h"
#include "Flower.h"
#include "Coin.h"
#include "Star.h"
#include "GoodMushroom.h"


Item::Item()
{
}

Item::~Item(){
	delete this->texture;
    delete this->sprite;
    delete this->shape;
    delete this->animation;
}

Item* Item::createItem(ID type, const std::string& image_file, sf::Vector2f position, sf::Vector2f size){
    Item* result = nullptr;

    switch (type)
    {
    case ID::flower:
        result = new Flower;
        break;
    case ID::star:
        result = new Star;
        break;
    case ID::good_mushroom:
        result = new GoodMushroom;
        break;
    case ID::coin:
        result = new Coin;
        break;
    default:
        result = nullptr;
        break;
    }

    if (result)
    {
        result->texture = new sf::Texture;
        if (!result->texture->loadFromFile(image_file)) exit(1);

        result->shape->setSize(size);
        result->sprite->setTexture(*(result->texture));
        result->position = position;
    }

    return result;
}

void Item::move(){}

void Item::die(){
    this->alive = false;
}

void Item::beingCollected(){}

void Item::reset(){
    this->baseGround = std::numeric_limits<float>::max();
}

bool Item::isDead()
{
    return !(this->alive);
}

void Item::update(){

}

void Item::draw(sf::RenderWindow* window){
    window->draw(*(this->sprite));
    window->draw(*(this->shape));
}

void Item::twinkle(){}


