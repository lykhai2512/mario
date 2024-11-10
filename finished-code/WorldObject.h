#pragma once

#include <SFML/Graphics.hpp>


class WorldObject {
private:
    
public:
    WorldObject();
    virtual void move() = 0;
    virtual void jump() = 0;
    virtual void die() = 0;
};



 






