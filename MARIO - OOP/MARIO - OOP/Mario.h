#pragma once
#include "Character.h"
#include "Map.h"
#include "Renderer.h"

class Mario : public Character {
public:
    Mario(float x, float y);

    void Update(float deltaTime, Map& map) override;  // Override pure virtual function
    void Render(Renderer& renderer) override;        // Override pure virtual function
    void setPosition(const sf::Vector2f& newPosition);

private:
    float angle = 0.0f; // Rotation angle, if needed
};
