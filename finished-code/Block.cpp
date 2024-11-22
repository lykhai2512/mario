#include "Block.h"
#include "Ground.h"
#include "Brick.h"
#include "BonusBrick.h"
#include "HorizontalPipe.h"
#include "VerticalPipe.h"
#include "BaseBrick.h"
#include "Cloud.h"
#include "Castle.h"
#include "Flag.h"
#include "Tree.h"
#include "Mountain.h"
#include "IndestructibleBrick.h"
#include "AssetManager.h"


Block::Block(){}

Block::~Block(){
	delete this->texture;
    delete this->sprite;
}

Block* Block::createBlock(ID type, const std::string &image_file, sf::Vector2f position, sf::Vector2f size)
{
    Block* result = nullptr;

    switch (type)
    {
    case ID::ground:
        result = new Ground;
        break;
    case ID::indestructible_brick:
        result = new IndestructibleBrick;
        break;
    case ID::base_brick:
        result = new BaseBrick;
        break;
    case ID::brick:
        result = new HorizontalPipe;
        break;
    case ID::vertical_pipe:
    case ID::vertical_pipe_top:
        result = new VerticalPipe;
        break;
    case ID::horizontal_pipe:
        result = new Cloud;
        break;
    case ID::bonus_brick:
        result = new BonusBrick;
        break;
    case ID::small_tree:
    case ID::big_tree:
        result = new Tree;
    case ID::mountain:
        result = new Mountain;
        break;
    case ID::cloud:
        result = new Cloud;
        break;
    case ID::castle:
        result = new Castle;
        break;
    case ID::flag:
        result = new Flag;
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
        result->sprite->setTexture(*(result->texture));
        result->position = position;
    }
    
    return result;
}

void Block::die() {
    this->alive = false;
}

bool Block::isDead() {
    return !this->alive;
}
void Block::draw(sf::RenderWindow* window) {
    this->update();
    window->draw(this->shape);
}

void Block::update() {
    
}

void Block::beingStoodOn() {

}

void Block::beingHit() {

}