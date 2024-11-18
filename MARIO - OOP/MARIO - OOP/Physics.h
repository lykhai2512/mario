#pragma once
#include <SFML/Graphics.hpp>

class Physics
{
public:
    Physics(float gravity = 9.8f, float jumpStrength = -250.0f, float groundLevel = 500.0f);

    void ApplyGravity(float deltaTime, float& verticalVelocity); // Use reference to modify verticalVelocity
    void ApplyJump(float& verticalVelocity);                    // Use reference to modify verticalVelocity
    void Update(float deltaTime, sf::Vector2f& position, float& verticalVelocity, bool& isOnGround);

private:
    float gravity;
    float jumpStrength;
    float groundLevel;
};
