#pragma once

#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Renderer.h"

class Character {
public:
    Character(float x, float y, float speed);

    // Pure virtual methods
    virtual void Update(float deltaTime, Map& map) = 0;
    virtual void Render(Renderer& renderer) = 0;
    virtual void setPosition(const sf::Vector2f& newPosition) = 0;

protected:
    sf::Vector2f position;
    float speed;
    float angle = 0.0f;
};
