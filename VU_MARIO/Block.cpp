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
#include "AutomaticStrategy.h"


Block::Block(){}

Block::~Block(){
    delete shape;
}

Block* Block::createBlock(BlockType type, sf::Vector2f position)
{
    Block* result = nullptr;

    switch (type)
    {
    case BlockType::ground:
        result = new Ground;
        break;
    case BlockType::indestructible:
        result = new IndestructibleBrick;
        break;
    case BlockType::basebrick:
        result = new BaseBrick;
        break;
    case BlockType::brick:
        result = new HorizontalPipe;
        break;
    case BlockType::vertical_pipe:
    case BlockType::vertical_pipe_top:
        result = new VerticalPipe;
        break;
        //need animation
    case BlockType::bonus:
        result = new BonusBrick({new AutomaticStrategy});
        break;
    case BlockType::tree:
        result = new Tree;
        break;
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
        AssetManager* instance = AssetManager::getInstance();
        result->shape = new sf::RectangleShape;

        std::pair<sf::Texture*, sf::IntRect> temp = instance->getBlock(type);

        sf::IntRect intRect = temp.second;

        sf::FloatRect floatRect(
            static_cast<float>(intRect.left),
            static_cast<float>(intRect.top),
            static_cast<float>(intRect.width),
            static_cast<float>(intRect.height)
        );

        result->shape->setSize(sf::Vector2f(floatRect.width, floatRect.height));

        result->shape->setTexture(temp.first);
        result->shape->setTextureRect(temp.second);

        position.y -= temp.second.getSize().y;
        result->position = position;
        result->baseGround = position.y;
        
        result->shape->setPosition(position);
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
    window->draw(*this->shape);
}

void Block::update() {
    
}

void Block::beingStoodOn(float& baseGround, const sf::FloatRect& bounds) {
    sf::FloatRect m_bounds = shape->getGlobalBounds();
    
    if (bounds.left + bounds.width >= m_bounds.left && bounds.left <= m_bounds.left + m_bounds.width) {
        if (this->position.y >= bounds.top + 15.f && position.y < baseGround) {
            baseGround = position.y;
        }
    }
}

void Block::beingHit(const sf::FloatRect& bounds, float& baseRoof, sf::Vector2f& position) {
    sf::FloatRect m_bounds = this->shape->getGlobalBounds();

    if (bounds.left + bounds.width >= m_bounds.left && bounds.left <= m_bounds.left + m_bounds.width) {
        if (this->position.y <= bounds.top && this->position.y > baseRoof) {
            baseRoof = this->position.y;
        }
        
        if (bounds.left + bounds.width < m_bounds.left + m_bounds.width) {
            if (bounds.intersects(m_bounds)) {
                position.x = m_bounds.left - bounds.width;
            }
        }

        else{
            if (bounds.intersects(m_bounds)) {
                position.x = m_bounds.left + m_bounds.width;
            }
        }
    }

}

void Block::beingHitByNonPlayable(const sf::FloatRect& bounds, float& speed){
    sf::FloatRect m_bounds = this->shape->getGlobalBounds();

    if (bounds.left + bounds.width >= m_bounds.left && bounds.left <= m_bounds.left + m_bounds.width) {

        if (bounds.intersects(m_bounds)) {
            
            speed = -speed;
            
            if (bounds.left < m_bounds.left + m_bounds.width) {
                this->position.x = m_bounds.left - bounds.width;
            }

            else {
                this->position.x = m_bounds.left + m_bounds.width;
            }
        }

        
    }
}
