#pragma once

#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Map.h"
#include "Renderer.h"

class Mario : public Character {
public:
    Mario(float x, float y);
    void Update(float deltaTime, Map& map) override;
    void Render(Renderer& renderer) override;
    void setPosition(const sf::Vector2f& newPosition) override;  // Declaration only

private:
    float jumpStrength = 100.0f;
    float gravity = 60.0f;
    float verticalVelocity = 0.0f;
    bool isJumping = false;
    bool isGrounded = true;
};
