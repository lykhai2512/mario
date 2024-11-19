#pragma once

#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class WorldObject {
private:
    
public:
    WorldObject();
    virtual void move() = 0;
    virtual void jump() = 0;
    virtual void die() = 0;
    
    virtual void collect(WorldObject* item) = 0;
    virtual void beingCollected(sf::Vector2f &position,sf::Texture* &texture,sf::FloatRect& bounds,float &baseGround) = 0;
    
    virtual void standOn(WorldObject* block) = 0;
    virtual void beingStoodOn(sf::Vector2f& position, sf::Texture* texture, sf::FloatRect& bounds, float &baseGround) = 0;

    virtual void hit(WorldObject* object) = 0;
    virtual void beingHit(sf::Vector2f& position, sf::Texture* texture, sf::FloatRect& bounds, float &baseGround) = 0;


    virtual bool isDead() = 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow* window) = 0;

};



 






