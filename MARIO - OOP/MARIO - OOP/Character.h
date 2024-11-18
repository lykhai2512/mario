#pragma once
#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "Map.h"

class Character {
public:
    Character(float x, float y, float speed);

    virtual void Update(float deltaTime, Map& map) = 0;  // Pure virtual function
    virtual void Render(Renderer& renderer) = 0;        // Pure virtual function, should match the derived class signature

protected:
    sf::Vector2f position;
    float speed;
};
