#include "Mario.h"
#include "Renderer.h"
#include "Resources.h"
#include "Map.h"
#include <SFML/Graphics.hpp>

Mario::Mario(float x, float y)
    : Character(x, y, 100.0f) {
}

void Mario::Update(float deltaTime, Map& map)
{
    // Horizontal movement (left-right)
    sf::Vector2f oldPosition = position;
    sf::FloatRect marioBounds(position, sf::Vector2f(32, 32));  // Mario's size (32x32)

    float movementSpeed = speed * deltaTime;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        position.x += movementSpeed;
        marioBounds.left = position.x;
        if (map.IsCollidingWithBrick(marioBounds)) {
            position.x = oldPosition.x;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        position.x -= movementSpeed;
        marioBounds.left = position.x;
        if (map.IsCollidingWithBrick(marioBounds)) {
            position.x = oldPosition.x;
        }
    }

    // Jumping and Gravity Logic
    if (isGrounded && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        isJumping = true;
        verticalVelocity = -jumpStrength;  // Apply initial jump force
        isGrounded = false;
    }

    // Gravity and falling
    if (!isGrounded) {
        verticalVelocity += gravity * deltaTime;  // Apply gravity
        position.y += verticalVelocity * deltaTime;  // Move vertically

        marioBounds.top = position.y;
        if (map.IsCollidingWithBrick(marioBounds)) {
            position.y = oldPosition.y;  // Revert the position
            isJumping = false;
            isGrounded = true;
            verticalVelocity = 0;  // Stop falling
        }
    }
}

void Mario::Render(Renderer& renderer) {
    sf::Sprite sprite;
    sprite.setTexture(Resources::textures["mario.png"]);
    sprite.setOrigin(16, 16);  // Assuming the sprite is 32x32
    sprite.setRotation(angle);  // Apply rotation based on angle
    renderer.Draw(Resources::textures["mario.png"], position, sf::Vector2f(32, 32));
}

void Mario::setPosition(const sf::Vector2f& newPosition) {
    position = newPosition;  // Definition of setPosition
}