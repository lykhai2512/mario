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
    if (this->position.y < this->baseGround - this->shape->getSize().y) {
        this->position.y += 5.f;
    }

    else {
        this->position.y = this->baseGround - this->shape->getSize().y;
    }
    

    this->shape->setPosition(this->shape->getPosition().x,this->position.y);
}

void Block::beingStoodOn(float& baseGround, const sf::FloatRect& bounds) {
    sf::FloatRect m_bounds = shape->getGlobalBounds();
    
    if (bounds.left + bounds.width > m_bounds.left && bounds.left < m_bounds.left + m_bounds.width) {
        if (this->position.y >= bounds.top + 15.f && position.y < baseGround) {
            baseGround = position.y;
        }
    }
}


void Block::beingHit(const sf::FloatRect& bounds, sf::Vector2f& position) {
    sf::FloatRect m_bounds = shape->getGlobalBounds();

    if (bounds.intersects(m_bounds)) {
        if (bounds.left + bounds.width <= m_bounds.left + 5.f) {
            position.x = m_bounds.left - bounds.width;
        }
        
        else if (bounds.left >= m_bounds.left + m_bounds.width - 5.f) {
            position.x = m_bounds.left + m_bounds.width;
        }

        else {
            position.y = m_bounds.top + m_bounds.height;
        }
    }
}


void Block::beingHitByNonPlayable(const sf::FloatRect& bounds, float& speed){
    sf::FloatRect m_bounds = this->shape->getGlobalBounds();

    if (bounds.left + bounds.width >= m_bounds.left && bounds.left <= m_bounds.left + m_bounds.width) {

        if (bounds.intersects(m_bounds)) {
            
            speed *= -1;
            
            if (bounds.left < m_bounds.left + m_bounds.width) {
                this->position.x = m_bounds.left - bounds.width;
            }

            else {
                this->position.x = m_bounds.left + m_bounds.width;
            }
        }

        
    }
}
