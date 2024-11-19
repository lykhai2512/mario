#include "Item.h"
#include "Flower.h"
#include "Coin.h"
#include "Star.h"
#include "GoodMushroom.h"


Item::Item()
{
}

Item::~Item(){
	delete texture;
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

        result->shape.setSize(size);
        result->shape.setTexture(result->texture);
        result->position = position;
    }

    return result;
}

void Item::move()
{
}

void Item::jump()
{
}

void Item::die()
{
}

void Item::collect(WorldObject* item)
{
}

void Item::beingCollected(sf::Vector2f& position, sf::Texture*& texture, sf::FloatRect& bounds, float& baseGround)
{
}

void Item::standOn(WorldObject* block)
{
}

void Item::beingStoodOn(sf::Vector2f& position, sf::Texture* texture, sf::FloatRect& bounds, float& baseGround)
{
}

void Item::hit(WorldObject* object)
{
}

void Item::beingHit(sf::Vector2f& position, sf::Texture* texture, sf::FloatRect& bounds, float& baseGround)
{
}

bool Item::isDead()
{
    return false;
}

void Item::update()
{
}

void Item::draw(sf::RenderWindow* window)
{
}

