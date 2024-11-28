#include "Item.h"
#include "Flower.h"
#include "Coin.h"
#include "Star.h"
#include "GoodMushroom.h"
#include "AutomaticStrategy.h"
#include "Animation.h"

Item::Item(){}

Item::~Item(){
    delete this->sprite;
    delete this->shape;
    delete this->animation;
}

Item* Item::createItem(ItemType type, sf::Vector2f position){
    Item* result = nullptr;

    switch (type)
    {
    case ItemType::flower:
        result = new Flower;
        break;
    case ItemType::star:
        result = new Star;
        break;
    case ItemType::mushroom:
        result = new GoodMushroom;
        break;
    case ItemType::coin:
        result = new Coin;
        break;
    default:
        result = nullptr;
        break;
    }

    if (result)
    {
        AssetManager* instance = AssetManager::getInstance();
        result->shape = new sf::RectangleShape;
        result->sprite = new sf::Sprite;

        std::pair<sf::Texture*, std::vector<sf::IntRect>> temp = instance->getItem(type);
        
        sf::IntRect intRect = temp.second[0];

        sf::FloatRect floatRect(
            static_cast<float>(intRect.left),
            static_cast<float>(intRect.top),
            static_cast<float>(intRect.width),
            static_cast<float>(intRect.height)
        );


        result->shape->setSize(sf::Vector2f(floatRect.width, floatRect.height));

        result->sprite->setTexture(*temp.first);
        result->sprite->setTextureRect(intRect);

        result->animation = new Animation({ new AutomaticStrategy(temp.first,temp.second,1.0 / 60)});

        position.y -= floatRect.getSize().y;
        result->position = position;
        
        result->baseGround = position.y;

    }

    return result;
}

void Item::move(){}

void Item::die(){
    this->alive = false;
}

void Item::beingCollected(const sf::FloatRect& bounds){
    sf::FloatRect m_bounds = this->shape->getGlobalBounds();

    if (bounds.intersects(m_bounds)) {
        this->die();
        //observer->notify
        //sound
    }
}

void Item::reset(){
    this->baseGround = std::numeric_limits<float>::max();
}

bool Item::isDead()
{
    return !(this->alive);
}

void Item::update(){
    if (this->position.y < this->baseGround - this->shape->getSize().y) {
        this->position.y += 5.f;
    }
    else {
        this->position.y = this->baseGround - this->shape->getSize().y;
    }

    this->sprite->setPosition(this->position);
    this->shape->setPosition(this->position);
}

void Item::draw(sf::RenderWindow* window){
    window->draw(*(this->sprite));
}

void Item::twinkle(){}


