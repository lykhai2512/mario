#pragma once

#include <SFML/Graphics.hpp>


class WorldObject {
private:
    
public:
    WorldObject();
    virtual void move(float dt) = 0;
    virtual void jump() = 0;
    virtual void die() = 0;
    virtual void collect(WorldObject* object) = 0;
    virtual void standOn(WorldObject* object) = 0;
    virtual void setPositionFor(WorldObject* object) = 0;
    virtual void hit(WorldObject* object) = 0;
    virtual bool isDead() = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
};



 






