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

std::map<int,sf::Vector2f> Block::size = std::map<int, sf::Vector2f> {
    {0,sf::Vector2f(32.f,32.f)},
    {1,sf::Vector2f(32.f,32.f)},
    {2,sf::Vector2f(32.f,32.f)},
    {3,sf::Vector2f(32.f,32.f)},
    {4,sf::Vector2f(50.f,100.f)},
    {5,sf::Vector2f(100.f,150.f)},
    {6,sf::Vector2f(32.f,32.f)},
    {7,sf::Vector2f(50.f,50.f)},
    {8,sf::Vector2f(300.f,400.f)},
    {9,sf::Vector2f(20.f,500.f)},
    {10,sf::Vector2f(50.f,50.f)},
    {11,sf::Vector2f(32.f,32.f)},
    {12,sf::Vector2f(32.f,32.f)},
    {13,sf::Vector2f(32.f,32.f)},
};

Block::Block(){}

Block::~Block(){
	delete texture;
}

Block* Block::createBlock(BlockType type, const std::string &image_file, sf::Vector2f position)
{
    Block* result = nullptr;

    switch (type)
    {
    case BlockType::ground:
        result = new Ground;
        break;
    case BlockType::indestructible_brick:
        result = new IndestructibleBrick;
        break;
    case BlockType::base_brick:
        result = new BaseBrick;
        break;
    case BlockType::brick:
        result = new HorizontalPipe;
        break;
    case BlockType::vertical_pipe:
    case BlockType::vertical_pipe_top:
        result = new VerticalPipe;
        break;
    case BlockType::horizontal_pipe:
        result = new Cloud;
        break;
    case BlockType::bonus_brick:
        result = new BonusBrick;
        break;
    case BlockType::small_tree:
    case BlockType::big_tree:
        result = new Tree;
    case BlockType::mountain:
        result = new Mountain;
        break;
    case BlockType::cloud:
        result = new Cloud;
        break;
    case BlockType::castle:
        result = new Castle;
        break;
    case BlockType::flag:
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

        result->shape.setSize(size[(int)type]);
        result->shape.setTexture(result->texture);
        result->position = position;
    }
    
    return result;
}

void Block::move() {}

void Block::jump() {}

void Block::die() {
	alive = false;
}

void Block::collect(WorldObject *object) {}

void Block::standOn(WorldObject *object) {}

void Block::setPositionFor(WorldObject *object) {}

void Block::hit(WorldObject *object) {}

bool Block::isDead() {
	return !alive;
}

void Block::draw(sf::RenderWindow* window){
	this->shape.setPosition(position);
	window->draw(this->shape);
}


