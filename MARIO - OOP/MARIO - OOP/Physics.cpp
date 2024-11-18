#include "Physics.h"

Physics::Physics(float gravity, float jumpStrength, float groundLevel)
    : gravity(gravity), jumpStrength(jumpStrength), groundLevel(groundLevel) {
}

void Physics::ApplyGravity(float deltaTime, float& verticalVelocity)
{
    // Apply gravity to verticalVelocity
    verticalVelocity += gravity * deltaTime;
}

void Physics::ApplyJump(float& verticalVelocity)
{
    // Set vertical velocity to jumpStrength when Mario jumps
    verticalVelocity = jumpStrength;
}

void Physics::Update(float deltaTime, sf::Vector2f& position, float& verticalVelocity, bool& isOnGround)
{
    // Update vertical position based on velocity
    position.y += verticalVelocity * deltaTime;

    // Apply gravity
    ApplyGravity(deltaTime, verticalVelocity);

    // Check if Mario has hit the ground
    if (position.y >= groundLevel)
    {
        position.y = groundLevel;
        verticalVelocity = 0;  // Stop vertical movement
        isOnGround = true;      // Mario is on the ground
    }
    else
    {
        isOnGround = false;     // Mario is in the air
    }
}
